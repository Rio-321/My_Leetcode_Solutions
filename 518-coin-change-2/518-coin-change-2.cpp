class Solution {
public:
    
    int f(vector<int> &coins, int ind, int sum, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            dp[sum][ind] = (sum%coins[0]==0);
            return dp[sum][ind];
        }
        
        
        if(dp[sum][ind]!=-1) return dp[sum][ind];
        
        
        int notTake = f(coins,ind-1,sum,dp);
        int take = 0;
        
        if(coins[ind]<=sum)
            take = f(coins,ind, sum-coins[ind],dp);
        
        dp[sum][ind] = take + notTake; 
        
        return dp[sum][ind];
    }
    
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(amount+1, vector<int>(n,-1));
        
        return f(coins,n-1,amount,dp);
        
    }
};