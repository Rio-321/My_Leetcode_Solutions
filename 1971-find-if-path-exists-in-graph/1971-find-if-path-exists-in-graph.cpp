bool DFS(vector<int> adj[], int src, int dest,vector<bool> &visited)
{
    visited[src] = true;
    
    if(src==dest)
        return true;
    
    for(int x: adj[src])
    {
        if(!visited[x])
        { 
            if(DFS(adj,x,dest,visited)==true)
                return true;
        }
    }
    
    return false;
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        int E = edges.size();
        
        vector<int> adj[n];
        
        for(int i=0;i<E;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<bool> visited(n);
        
        if(DFS(adj,source,destination,visited))
            return true;
        
        return false;
        
    }
};