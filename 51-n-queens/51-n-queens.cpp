class Solution {
public:
    
    //Optimized Solution
     vector<vector<string>> ans;
    
     bool is_safe(vector<string> &board, int row, int col)
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
        
        for(int i=row,j=col;i<board.size()&&j>=0;i++,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
             
        return true;
    }
    
    void Solve_Queen(vector<string> &board,int col)
    {
        if(col==board.size()) 
        {
            ans.push_back(board);
            return ;
        }
        
        for(int i=0;i<board.size();i++)
        {
            if(is_safe(board,i,col))
            {
                 board[i][col] = 'Q';
                
                 Solve_Queen(board,col+1);

                 board[i][col] = '.';
            }
        }
        
        return;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n,string(n,'.'));
        
        
        Solve_Queen(board,0);
     
        
        return ans;
        
    }
};

// https://leetcode.com/problems/n-queens/discuss/810358/C%2B%2B-4ms-Heavily-Commented-Clean-Solution-or-Fast-and-Easy-or-Explanation

// TC= O(n^3)