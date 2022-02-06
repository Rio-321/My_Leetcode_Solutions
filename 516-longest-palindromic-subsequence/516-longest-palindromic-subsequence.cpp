class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        
        int n = s.length();
        
        if(n==0)
            return 0;
        
         string t = s;
        reverse(t.begin(), t.end());
        
        // cout<<t<<"\n";
        
        
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(t[i-1]==s[j-1])
                {
                   // res = res + t[i-1]; 
                   // cout<<i<<" and "<<j<<"- "<<res<<"\n";
                   dp[i][j] = dp[i-1][j-1] + 1; 
                    
                }  
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
        
        
    }
};