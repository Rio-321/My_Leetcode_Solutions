class Solution {
public:
    int superEggDrop(int k, int n) {
        // k = eggs & n = floors
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
         // dp[i][j] = floor and eggs
        
        // if i==1 return 1
        for(int j=1;j<=k;j++)
            dp[1][j] = 1;
        
        //j==1 (eggs==1) 
        for(int i=1;i<=n;i++)
           dp[i][1] = i;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                dp[i][j] = INT_MAX;
                int l = 1,h = i;
                
                while(l<=h)
                {
                    int x = (l+h)/2;
                    int left = dp[x-1][j-1];
                    int right = dp[i-x][j];
                    
                    int temp = 1 + max(left, right);
                    
                    if(left<right)
                        l = x+1;
                    else
                        h = x-1;
                    
                    dp[i][j] = min(dp[i][j], temp);
                    
                }
                
//                 for(int x=1;x<=i;x++)
//                 {
//                     int temp = 1 + max(dp[x-1][j-1], dp[i-x][j]);
                    
//                     dp[i][j] = min(dp[i][j], temp);
//                 }
            }
        }
         
        
        return dp[n][k];
        
    }
};