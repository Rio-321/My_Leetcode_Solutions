class Solution {
public:
    int n;
    int DFS(int i, int j, vector<vector<int>> &grid, int &index)
    {
        grid[i][j] = index;
        
        int move[5] = {-1, 0, 1, 0, -1};
        int count = 1;
        for(int k=0;k<4;k++)
        {
            int newi = i + move[k];
            int newj = j + move[k+1];
            
    if(newi >= 0 && newi < n && newj >= 0 && newj < n && grid[newi][newj] == 1)
            {
               count +=  DFS(newi, newj, grid, index);
            }
        }
        
        return count;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        n = grid.size();
        
        vector<int> area(n*n + 2);
        
        int index = 2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    area[index] = DFS(i,j,grid, index);
                    index++;
                }
            }
        }
        
        int ans = 0;
        for(auto &x: area)
            ans = max(ans, x);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {   
                    unordered_set<int> neighbor;
                    int move[5] = {-1, 0, 1, 0, -1};
                    
                    for(int k=0;k<4;k++)
                    {
                          int newi = i + move[k];
                          int newj = j + move[k+1];
            
    if(newi >= 0 && newi < n && newj >= 0 && newj < n && grid[newi][newj] > 1)
            {
               neighbor.insert(grid[newi][newj]);
            }
                    }
                    
                    int res = 1;
                    for(auto &x: neighbor)
                        res += area[x];
                    
                    ans = max(ans, res);
                    
                }
            }
        }
        
        return ans;
        
    }
};