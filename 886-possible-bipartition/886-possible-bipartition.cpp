bool DFS(vector<int> adj[], int curr, int par, int col, vector<bool> &visited, vector<int> &color)
{   
    visited[curr] = true;
    color[curr] = col;
    
    for(int x: adj[curr])
    {  
        if(!visited[x])
        {   
            if(DFS(adj,x,curr,!col,visited,color)==false)
                return false;
        }
        else
        {
            if(color[x]==color[curr])
                return false;
        }
           
    }
    
    return true;
}

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_set<int> A,B;
        int l = dislikes.size();
        
        vector<int> adj[n+1];
        
        for(int i=0;i<l;i++)
        {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);             
        }
        
        vector<bool> visited(n+1);
        vector<int> color(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {   
            if(!visited[i])
                if(DFS(adj,i,0,1,visited,color)==false)
                    return false;
        }
        
        return true;
        
        
    }
};