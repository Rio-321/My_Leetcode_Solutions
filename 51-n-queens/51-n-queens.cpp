class Solution {
public:
     vector<vector<string>> ans;
    
     bool is_safe(vector<string> &board, int row, int col,int n)
    {
        for(int j=0;j<col;j++)
        {
            if(board[row][j]=='Q')
                return false;
        }
        
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        
        for(int i=row,j=col;i<n&&j>=0;i++,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
             
        return true;
    }
    
    void Solve_Queen(vector<string> &board,int col, int n)
    {
        if(col==n) 
        {
            ans.push_back(board);
            return ;
        }
        
        for(int i=0;i<n;i++)
        {
            if(is_safe(board,i,col,n))
            {
                board[i][col] = 'Q';
                
                 Solve_Queen(board,col+1,n);

                    board[i][col] = '.';
            }
        }
        
        // return false;
        return;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        string temp = "";
        for(int i=0;i<n;i++)
            temp.push_back('.');
        
        vector<string> board(n,temp);

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<board[i][j];
        //     cout<<"\n";
        // }
        
        
        Solve_Queen(board,0,n);
     
        
        return ans;
        
    }
};