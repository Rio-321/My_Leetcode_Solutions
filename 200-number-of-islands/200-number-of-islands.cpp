



class Solution {
public:
    
    int n,m;

// bool isSafe(int x, int y)
// {
//     if(x>=0 && x<m && y>=0 && y<n)
//         return true;
    
//     return false;
// }

    
    void BFS(int i, int j, vector<vector<char>> &grid)
{
        
//         grid[i][j] = '2';
        
//         int move[5] = {-1,0,1,0,-1};
//         for(int k=0;k<4;k++)
//         {
//             int Newx = i + move[k];
//             int Newy = j + move[k+1];
            
//             if(isSafe(Newx,Newy) && grid[Newx][Newy] == '1')
//             {
//                 BFS(Newx, Newy, grid);
//             }
            
//         }
        
        
    queue<int> q;
    q.push(n*i+j);
    grid[i][j] = '2';
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        int x = curr/n;
        int y = curr%n;
        
        
        
        int move[5] = {-1,0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int Newx = x + move[k];
            int Newy = y + move[k+1];
            
            if((Newx>=0 && Newx<m && Newy>=0 && Newy<n) && grid[Newx][Newy] == '1')
            {
                grid[Newx][Newy] = '2';
                q.push(n*Newx + Newy);
            }
            
        }
        

    }
}

    
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        m = grid.size();
        n = grid[0].size();

        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    BFS(i,j, grid);
                    count++;
                }      
            }

        }
     
        return count;
        
    }
};