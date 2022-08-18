class Solution {
public:
    
    int func(int ind, vector<int> &prices, int buy, vector<vector<int>> &dp)
    {
        if(ind == prices.size())
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        
        if(buy)
        {
            return dp[ind][buy] = max((-prices[ind] + func(ind+1, prices, 0, dp)),
                      (func(ind+1, prices, 1, dp)));
        }
        else
            return dp[ind][buy] = max((prices[ind] + func(ind+1, prices, 1, dp)),
                      func(ind+1, prices, 0, dp));
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return func(0, prices, 1, dp);
        
    }
};






//         int n = prices.size();
//         if(n == 1) return 0;
        
//         int profit = 0;
//         for(int i=1;i<n;i++)
//         {
//             if(prices[i] > prices[i-1])
//                 profit = profit + (prices[i] - prices[i-1]);
//         }
        
//         return profit;