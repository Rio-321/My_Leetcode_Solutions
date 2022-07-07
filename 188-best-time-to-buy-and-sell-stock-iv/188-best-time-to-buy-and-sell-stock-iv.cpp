class Solution {
public:
    
    int solve(int start, vector<int> &prices, int k, vector<vector<int>> &dp)
    {
        
         int n = prices.size();
         if(k == 0 || start == n)
            return 0;
        
        
        if(dp[start][k] != -1)
             return dp[start][k];
        
        
        int res = 0;
        int profit = 0;
        int mini = prices[start];
        
        for(int i=start+1;i<n;i++)
        {  
             profit = max(profit, prices[i]-mini);
             
             res = max(res, profit + solve(i+1, prices, k-1, dp));
            
             mini = min(mini, prices[i]);
            
        }
        
        return dp[start][k] = res;
        
        
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
            
        vector<vector<int>> dp(prices.size()+1, vector<int>(k+1, -1));
        
        return solve(0, prices, k, dp);
        
    }
};