class Solution {
public:
    int n = 0, m = 0;
    int BFS(int i, int j, vector<vector<int>> &grid)
    {
        int count = 1;
        
        int move[5] = {-1,0,1,0,-1};
        
        queue<int> q;
        q.push(n*i+j);
        grid[i][j] = 2;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            // grid[curr/n][curr%n] = 2;
            
            for(int k=0;k<4;k++)
            {
                int i1 = curr/n + move[k];
                int j1 = curr%n + move[k+1];

                if(i1>=0 && i1<m && j1>=0 && j1<n && grid[i1][j1] == 1)
                {
                    count++;
                    q.push(n*i1+j1);
                    grid[i1][j1] = 2;
                }
            }
        }
        
        return count;
    }
    
    
int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        int res = 0;
    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                    res = max(res, BFS(i,j,grid));
            }
        }
        
        return res;
    }
};