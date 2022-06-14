class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        // int n = grid[0].size();
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push(n*i+j);
                    // grid[i][j] = 0;
                }
            }
        }
        int res = -1;
        
        if(q.size()==0 || q.size()==n*n)
            return res;
        
        
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            res = max(res,grid[curr/n][curr%n]);
            
            int move[5] = {-1,0,1,0,-1}; 
            
            for(int k=0;k<4;k++)
            {
                int x = curr/n + move[k];
                int y = curr%n + move[k+1];
                
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0)
                {
                    grid[x][y] = 1 + grid[curr/n][curr%n];
                    q.push(n*x+y);
                }
            }
        }
        
        return res-1;
    }
};