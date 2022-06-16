    int N = 200;
    vector<vector<int>> Board( N, vector<int>(N, 0));
class NumMatrix {
public:

    
    NumMatrix(vector<vector<int>>& matrix) {
        // Board = matrix;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            Board[i][j] = ((j>0) ? Board[i][j-1] : 0) + matrix[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        
        for(int i=row1;i<=row2;i++)
        {
            res = res + Board[i][col2] - ((col1>0) ? Board[i][col1-1] : 0);
        }

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */