class Solution {
public:
    // https://leetcode.com/problems/reorganize-string/discuss/972856/C%2B%2B-Priority-Queue-Hash-Map-Easy-Solution
    string reorganizeString(string s) {
        
        
        string res = "";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        
        for(auto c:s)
            mp[c]++;        // Nlog(N)
        
        
        for(auto m:mp)
            pq.push({m.second, m.first});  //N(log(N))
        
        s.erase(s.begin(), s.end());
        
        while(!pq.empty())
        {
            s = s + string(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        
        string temp = "";
        
        int l=0, r = (s.length()-1)/2+1;
        
        // cout<<l<<" "<<r;
        
        while(l<=(s.length()-1)/2 || r<s.length())
        {
            
            if(s[l]==s[r]) return "";
            
            temp = temp +  s[l] ;
            
            if(r<s.length())
            temp = temp + s[r];
            l++;
            r++;
        }
        
        // if(l==r)
        //     temp += s[l];
        
        
        return temp;
            
        
    }
};