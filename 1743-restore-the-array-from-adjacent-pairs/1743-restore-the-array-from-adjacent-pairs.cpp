class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        
    unordered_map<int, vector<int>> mp;
    
    int src = -1;
    
    for(auto x:arr)
    {
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }
    
    for(auto x:mp)
    {
        if(x.second.size() == 1)
           { 
            src = x.first;
            break;
        }
    }
    
    vector<int> ans;
    ans.push_back(src);
    unordered_set<int> visited;
    
    visited.insert(src);
    
    int curr = src;
    
    while(1)
    {
        bool flag = true;
       for(auto x:mp[curr])
        {
            if(visited.count(x) == 0)
            {
                flag = false;
                visited.insert(x);
                ans.push_back(x);
                curr = x;
                break;
            }  
        } 
        
        if(flag == true)
            break;
    }
    
    return ans;
    
    }
};