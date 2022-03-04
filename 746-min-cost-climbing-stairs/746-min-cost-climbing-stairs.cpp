class Solution {
public:
    
//     int f(int x,vector<int>& cost, vector<int> &dp)
//     {
//         if(dp[x]!=-1) return dp[x];
        
//         if(x==0||x==1) return 0;
        
//         dp[x] = min(f(x-1,cost,dp)+cost[x-1], f(x-2,cost,dp)+cost[x-2]);
        
//         return dp[x];
//     }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n+1, -1);
//         dp[0] = 0;
//         dp[1] = 0;
//         return f(n,cost,dp);
        
        
        dp[1] = 0;
        dp[0] = 0;
        
        for(int i=2;i<=n;i++)
            dp[i] = min(dp[i-1]+cost[i-1],  dp[i-2]+cost[i-2]);
        
        return dp[n];     
        
        
    }
};