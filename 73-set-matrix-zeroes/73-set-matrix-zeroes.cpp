class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // vector<int> zero_list;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        unordered_set<int> row_No, col_No;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row_No.insert(i);
                    col_No.insert(j);
                }
                    // zero_list.push_back(i*n+j);  
            }
        
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row_No.find(i)!=row_No.end() || col_No.find(j)!=col_No.end())
                    matrix[i][j] = 0;
            }
        }
        
        
//         for(int x:zero_list)
//         {
//             int row = x/n;
//             int col = x%n;
            
//             if(row_No.find(row)==row_No.end())  //not in row_No set
//             {
//                 for(int i=0;i<n;i++)
//                 matrix[row][i] = 0;
                
//                   row_No.insert(row);  
//             }
            
//             if(col_No.find(col)==col_No.end())
//             {
//                 for(int i=0;i<m;i++)
//                  matrix[i][col] = 0;
          
//                 col_No.insert(col);   
//             }
              
         
//         }
        
        
        // return matrix;
        
        
        
    }
};