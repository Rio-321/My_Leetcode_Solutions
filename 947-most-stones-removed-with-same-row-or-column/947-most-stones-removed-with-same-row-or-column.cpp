class Solution {
public:
    
   void  DFS(int src, vector<vector<int>> &stones, vector<bool> &visited, int n)
    {
        visited[src] = true;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && (stones[src][0] == stones[i][0] || stones[src][1] == stones[i][1]))
             DFS(i,stones,visited,n);
        }
        
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
      int n = stones.size();
        
      int res = 0;
      
      vector<bool> visited(n);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
             {DFS(i,stones,visited,n);
            res++;}
        }
        
        return n-res;
    }
};