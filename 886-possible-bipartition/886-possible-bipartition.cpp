bool DFS(vector<int> adj[], int curr, int par, int col,vector<int> &color)
{   
    // visited[curr] = true;
    color[curr] = col;
    
    for(int x: adj[curr])
    {  
        if(color[x]==-1)
        {   
            if(DFS(adj,x,curr,!col,color)==false)
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
        
        int l = dislikes.size();
        
        vector<int> adj[n+1];
        
        for(int i=0;i<l;i++)
        {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);             
        }
        
        // vector<bool> visited(n+1);
        vector<int> color(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {   
            if(color[i]==-1)
                if(DFS(adj,i,0,1,color)==false)
                    return false;
        }
        
        return true;
        
        
    }
};