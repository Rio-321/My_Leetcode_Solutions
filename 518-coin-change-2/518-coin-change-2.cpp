class Solution {
public:
    
    int func(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 1;
        
        if(i == -1)
            return 0;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int res = 0;
        res = func(i-1, amount, coins, dp);  //not taken
        
        if(amount >= coins[i])
            res += func(i, amount-coins[i], coins,dp);
        
        dp[i][amount] = res;
        
        return res;
    }
  
    
    int change(int amount, vector<int>& coins) {
      
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        return func(n-1, amount, coins, dp);
        
    }
};