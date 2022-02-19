class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // vector<int> zero_list;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool is_row = false, is_col = false;
        
        // unordered_set<int> row_No, col_No;
        
        for(int i=0;i<n;i++)
            if(matrix[0][i]==0)
            {
                is_row = true;
                break;
            }
                
        
        for(int i=0;i<m;i++)
            if(matrix[i][0]==0)
            {
                is_col = true;
                break;
            }
                
        
        
        for(int i=0;i<m;i++)
        {  
            for(int j=0;j<n;j++)
            {  
                if(matrix[i][j]==0)
                {   
                    // if(i==0)
                        // is_row = true;
                    
                    
                    // row_No.insert(i);
                    // col_No.insert(j);
                    
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                    // zero_list.push_back(i*n+j);  
            }
        
        }
            
         
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
        
        if(is_row)
        {
            for(int i=0;i<n;i++)
                matrix[0][i] = 0;
        }

        if(is_col)
        {
            for(int i=0;i<m;i++)
                matrix[i][0] = 0;
        }

        
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(row_No.find(i)!=row_No.end() || col_No.find(j)!=col_No.end())
        //             matrix[i][j] = 0;
        //     }
        // }
        
        
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