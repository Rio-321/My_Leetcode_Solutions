class Solution {
public:
    
    int func(int n, vector<int> &dp)
    {  
        if(dp[n] != -1)
            return dp[n];
        
        if(n == 2 || n == 3 )
            return n;
        
        int res = INT_MIN;
         
        
        for(int i=1; i <=n/2; i++)
        {
            res = max(res, func(n-i, dp)*i);
        }
        
        dp[n] = res;
        
        return res;
        
    }
    int integerBreak(int n) {
        
        if(n == 2) return 1;
        if(n == 3) return 2;
        
        vector<int> dp(n+1, -1);
        
        return func(n, dp);
    }
};