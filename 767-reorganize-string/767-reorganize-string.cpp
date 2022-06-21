// ----------------------------------Optimal Solution---------------->
// link - https://leetcode.com/problems/reorganize-string/discuss/972856/C%2B%2B-Priority-Queue-Hash-Map-Easy-Solution


class Solution {
public:

    string reorganizeString(string s) {
        
        string res = "";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        
        for(auto c:s)
            mp[c]++;        // Nlog(N)
        
        
        for(auto m:mp)
            pq.push({m.second, m.first});  //N(log(N))
        
        while(pq.size()>1)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            res = res + top1.second + top2.second;
            
            top1.first--;
            top2.first--;
            
            if(top2.first>0)
                pq.push({top2.first, top2.second});
            
            if(top1.first>0)
                pq.push({top1.first, top1.second});
        }
        
        
        if(!pq.empty())
        {
             if(pq.top().first>1)
                return "";
            else
                 res = res + pq.top().second;
        }
       
        
        return res;
            
        
    }
};