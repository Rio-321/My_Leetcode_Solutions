// Time - O(n*amount)
// space = O(n*amount)

//  Tabulation solution
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1, INT_MAX);
        int n = coins.size();
        
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j] <= i && dp[i-coins[j]] != INT_MAX)
                { 
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        
        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
        
    }
};