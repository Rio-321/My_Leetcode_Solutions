class Solution {
public:
    
    int m=0,n=0;
    
    int convert(vector<vector<int>> &board, int i, int j)
    {
        
            int i_move[4] = {0,1,1,1};
            int j_move[4] = {1,-1,0,1};
        
            int one = 0;
            
            for(int k=0;k<4;k++)
            {
                int x = i+i_move[k];
                int y = j+j_move[k];
                if(x>=0 && x<m && y>=0 && y<n)
                {
                    if(board[x][y] >= 10)
                    {
                        one++;
                    }
                    
                    if(board[i][j] >= 10)
                    {
                        board[x][y]++;
                    }
                        
                }
                    
            }
        
        return one;   
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        m = board.size();
        n = board[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 1)
                    board[i][j] = 10;
            }
        }
        
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(board[i][j]>=10) // curr is 1
               {
                   int one = board[i][j] - 10;
                   one = one  + convert(board,i,j);
                   
                   if(one == 2 || one == 3)
                       board[i][j] = 1;
                   else
                       board[i][j] = 0;
                   
               }
                else // curr is 0
                {
                    int one = board[i][j] - 0;
                    one = one + convert(board,i,j);
                    
                    if(one == 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
            }
        }
        
        
    
    }
};