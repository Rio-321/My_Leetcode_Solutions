class Solution {
public:
    
    void DFS(int src, vector<vector<int>>& isConnected, vector<bool> &visited)
    {
        visited[src] = true;
        
        int n = isConnected.size();
        for(int j=0;j<n;j++)
        {
            if(isConnected[src][j]==1 && !visited[j])
                DFS(j,isConnected,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool> visited(n);
        int count = 0 ;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DFS(i,isConnected,visited);
                count++;
            }
        }
        
        return count;
        
    }
};