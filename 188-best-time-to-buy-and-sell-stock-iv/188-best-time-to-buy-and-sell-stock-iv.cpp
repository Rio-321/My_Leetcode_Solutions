class Solution {
public:
    
    // Optimal solution - Tabulation solution
    
    
    int maxProfit(int k, vector<int>& prices) 
    {
           
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int ind=n-1; ind>=0;ind--)
        {   
            for(int trans=2*k-1; trans>=0; trans--)
            {
                
               if(trans%2 == 0)
               {
                   dp[ind][trans] = max(-prices[ind]+dp[ind+1][trans+1], dp[ind+1][trans]);
               }
              else
                {
                    dp[ind][trans] = max(prices[ind]+dp[ind+1][trans+1], dp[ind+1][trans]);
                }
                
            }
            
        }
            

        
        return dp[0][0];
               
        
    }
};