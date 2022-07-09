class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int getAbsoluteParent(int x)
    {
        if(parent[x] == x)
            return x;
        
        parent[x] = getAbsoluteParent(parent[x]);
            
        return parent[x];
        
    }
    
    void unionOf(int x, int y)
    {
        int px = getAbsoluteParent(x);
        int py = getAbsoluteParent(y);
        
        if(px != py)
        {
            if(rank[px] > rank[py])
                parent[py] = px;
            else if(rank[px] < rank[py])
                parent[px] = py;
            else
            {
                parent[px] = py;
                rank[py]++;
            }
        }
        
        return;
            
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        
        parent.resize(n);
    
        for(int i=0;i<n;i++)
            parent[i] = i;
        
     
        rank.resize(n, 1);
        
        map<string, int> mp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string temp = accounts[i][j];
                if(mp.find(temp) == mp.end()) // not found
                {
                    mp[temp] = i;
                    
                }
                else //found
                {
                    unionOf(mp[temp], i);
                }
            }
        }
        
        
        vector<vector<string>> ans;
        
        map<int, vector<string>> group;
        
        vector<bool> visited(n);

        for(auto x: mp)
        {        
              group[getAbsoluteParent(x.second)].push_back(x.first);
      
        }
        
        for(auto x: group)
        {
            vector<string> temp;
            temp.push_back(accounts[x.first][0]);
            for(auto y : x.second)
                temp.push_back(y);
            
            sort(temp.begin()+1, temp.end());
            ans.push_back(temp);
        }
        
        
        return ans;
        
        
    }
};