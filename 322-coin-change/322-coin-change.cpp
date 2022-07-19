// Time - O(n*amount)
// space = O(n*amount)

// Memoization solution
class Solution {
public:
    
    int solve(int i, int amount, vector<int> & coins, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 0;
        if(i == -1)
            return 100000;
        
        if(dp[amount][i] != -1)
            return dp[amount][i];
        
        
        int res = solve(i-1,amount,coins, dp);
        
        if(amount >= coins[i])
            res = min(res, solve(i, amount-coins[i], coins, dp)+1);
            
        return dp[amount][i] = res ;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0)
            return 0;
        
        int n = coins.size();
        
        vector<vector<int>> dp(amount+1, vector<int>(n+1,-1));
        
        solve(n-1,amount, coins, dp);
        
        if(dp[amount][n-1] > 10000)
            return -1;
        else
            return dp[amount][n-1];
        
    }
};