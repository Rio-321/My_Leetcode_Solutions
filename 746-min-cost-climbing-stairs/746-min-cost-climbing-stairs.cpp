class Solution {
public:
    
    int f(int x,vector<int>& cost, vector<int> &dp)
    {
        if(dp[x]!=-1) return dp[x];
        
        dp[x] = min(f(x-1,cost,dp)+cost[x-1], f(x-2,cost,dp)+cost[x-2]);
        
        return dp[x];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 0;
        return f(n,cost,dp);
    }
};