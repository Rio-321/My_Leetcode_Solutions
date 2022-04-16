class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
           dp[i][0] = matrix[i][0];
            res = res + dp[i][0];
        }
           
        cout<<res<<"\n";    
      
            
        
        for(int j=1;j<n;j++)
        {
           dp[0][j] = matrix[0][j]; 
            res = res + dp[0][j];
        }
        
        cout<<res<<"\n";
            

            
        
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                    dp[i][j] = 0;
                else
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+ 1;
                    
            
                res = res + dp[i][j];
            }
            
          
        }
        
        return res;
    }
};