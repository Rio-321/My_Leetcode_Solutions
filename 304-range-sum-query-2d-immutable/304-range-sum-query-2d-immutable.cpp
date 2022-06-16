class NumMatrix {
public:
    
    int rows,col;
    vector<vector<int>> Board;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = row>0 ? matrix[0].size() : 0;
        
        Board = vector<vector<int>>(row+1,vector<int>(col+1,0));
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                Board[i][j] = matrix[i-1][j-1] +  Board[i-1][j] + Board[i][j-1]  - Board[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       
        int res = Board[row2+1][col2+1] - Board[row2+1][col1] - Board[row1][col2+1] + Board[row1][col1]; 
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */