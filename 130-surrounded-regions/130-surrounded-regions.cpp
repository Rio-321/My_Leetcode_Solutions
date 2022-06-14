

class Solution {
public:
    
    int m=0,n=0;
    
    void DFS(int i, int j, vector<vector<char>> &board)
    {   

        board[i][j] = '*';

        int move[5] = {-1,0,1,0,-1};

        for(int k=0;k<4;k++)
        {  
            int x = i + move[k];
            int y = j + move[k+1];

            if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O')
            {
                DFS(x,y,board);
            }
        }
    }

    
    void solve(vector<vector<char>>& board) {
        
        m = board.size();
        n = board[0].size();
        
        // cout<<m<<" and "<<n<<"\n";
        
       for(int j=0;j<n;j++)
       {
           if(board[0][j]=='O')
               DFS(0,j,board);
       }
        
       for(int j=0;j<n;j++)
       {
           if(board[m-1][j]=='O')
               DFS(m-1,j,board);
       }
        
       for(int i=0;i<m;i++)
       {
           if(board[i][0]=='O')
               DFS(i,0,board);
       }
        
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O')
                DFS(i,n-1,board);
        }
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='*')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
        
    }
};