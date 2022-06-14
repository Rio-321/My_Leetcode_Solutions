class Solution {
public:
    
    int n = 0;
    queue<int> q;
    void paint(int i, int j, vector<vector<int>> &grid)
    {
        
        grid[i][j] = 2;
        q.push(n*i+j);
        
        int move[5] = {-1,0,1,0,-1};
        
        for(int k=0;k<4;k++)
        {
            int x = i+move[k];
            int y = j+move[k+1];
            
            if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1)
            {
                paint(x,y,grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        n = grid.size();
        
        bool found = false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    found = true;
                    paint(i,j,grid);
                    break;
                }
            }
            if(found)
                break;
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            int move[5] = {-1,0,1,0,-1};
        
            for(int k=0;k<4;k++)
            {
                int x = curr/n + move[k];
                int y = curr%n + move[k+1];

                if(x>=0 && x<n && y>=0 && y<n)
                {
                    if(grid[x][y]==1)
                    {
                       return (grid[curr/n][curr%n]-2); 
                    }
                    
                    if(grid[x][y]==0)
                    {
                        grid[x][y] = 1 + grid[curr/n][curr%n];
                        q.push(x*n+y);
                    }
                   
                }
            }
            
        }
        
        return 0;
       
    }
};