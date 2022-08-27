// Time -- > O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

// Space --> Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.


class Solution {
public:
    
    bool isValid(vector<vector<char>> &board,int row, int col, char c)
    {
        for(int i=0;i<9;i++)
        {
             if(board[row][i] == c)
                 return false;
            
             if(board[i][col] == c)
                 return false;
        }
        
        
        int x = (row/3)*3;
        int y = (col/3)*3;
        
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(board[i][j] == c)
                    return false;
            }
        }
        
        return true;
        
    }
    
    bool solve(vector<vector<char>> &board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                 if(board[i][j] == '.')
                 {
                     for(char c='1';c<='9';c++)
                     {
                         if(isValid(board, i, j, c))
                         {
                             board[i][j] = c;
                             
                             if(solve(board) == true)
                                return true;
                             else
                                board[i][j] = '.';
                             
                         }   
                     }
                     
                     return false;
                 }
            }
        }
        return true;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
          solve(board);
    }
};