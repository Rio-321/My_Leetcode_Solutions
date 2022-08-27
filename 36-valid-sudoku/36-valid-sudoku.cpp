class Solution {
public:
    
    bool isValid(vector<vector<char>> &board, int r, int c, char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][c] == ch)
                return false;
            
            if(board[r][i] == ch)
                return false;
        }
        
        int x = (r/3)*3;
        int y = (c/3)*3;
        
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(board[i][j] == ch)
                    return false;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size();
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {   
                    char ch = board[i][j];
                    board[i][j] = '.';
                    
                    if(!isValid(board, i, j, ch))
                        return false;
                    
                    board[i][j] = ch;
                }
            }
        }
        
        return true;
    }
};