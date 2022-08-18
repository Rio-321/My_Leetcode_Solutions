class Solution {
public:
    
    int func(int i, vector<int> &prices, int buy, vector<vector<int>> &dp)
    {
        if(i >= prices.size()) return 0;
        
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy)
        {
             return dp[i][buy] = max(-prices[i] + func(i+1, prices, 0, dp), func(i+1, prices, 1, dp));
        }
        else
        {
            return dp[i][buy] = max(prices[i] + func(i+2, prices, 1, dp),  func(i+1, prices, 0, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
       return func(0, prices, 1, dp);
        
    }
};