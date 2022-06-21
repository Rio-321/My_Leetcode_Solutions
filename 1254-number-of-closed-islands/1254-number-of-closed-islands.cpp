class Solution {
public:
    int m,n;
    
    void COLOR(vector<vector<int>> &grid, int i, int j)
    {
        grid[i][j] = 1;
        
        int move[5] = {-1,0,1,0,-1};
        
        for(int k=0;k<4;k++)
        {
            int x = i + move[k];
            int y = j + move[k+1];
            
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0)
                COLOR(grid,x,y);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==0)
                COLOR(grid,0,j);
            
            if(grid[m-1][j]==0)
                COLOR(grid,m-1,j);
        }
        
        for(int i=1;i<m-1;i++)
        {
            if(grid[i][0]==0)
                COLOR(grid,i,0);
            
            if(grid[i][n-1]==0)
                COLOR(grid,i,n-1);
        }
        
        
        int count = 0;
        
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(grid[i][j]==0)
                {
                    COLOR(grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
};