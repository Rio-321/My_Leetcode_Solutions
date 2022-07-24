class Solution {
public:
    vector<int> tin;
    vector<int> low;
    vector<bool> visited;
    int timer;
    vector<vector<int>> ans;
    
    void dfs(int src, int par, vector<vector<int>> &adj)
    {
        visited[src] = true;
        tin[src] = low[src] = timer++;
        
        for(auto &x : adj[src])
        {
            if(x == par)
                continue;
            
            if(!visited[x])
            {
                dfs(x,src,adj);
                low[src] = min(low[src], low[x]);
                if(low[x] > tin[src])
                {
                    ans.push_back({src,x});
                }
            }
            else
                low[src] = min(low[src], tin[x]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        vector<vector<int>> adj(n);
        
        for(auto &x: connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);  
        }
        
        tin.resize(n,-1);
        low.resize(n,-1);
        visited.resize(n);
        
        // for(auto x:tin)
        //     cout<<x<<" ";
        
        
        
        timer = 0;
        for(int i=0;i<n;i++)
                dfs(0,-1,adj);
        
        return ans;
        
    }
};