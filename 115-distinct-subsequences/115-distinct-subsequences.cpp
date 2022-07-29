class Solution {
public:
    int numDistinct(string s, string t) {
        
        int m = t.size();
        int n = s.size();
        
        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, 0));
        
        for(int j=0;j<n;j++)
        {
            if(s[j] == t[0])
                dp[0][j] = ((j>0) ? dp[0][j-1] : 0) + 1;
            else
                dp[0][j] = ((j>0) ? dp[0][j-1] : 0);
        }
        
        
        if(s[0] == t[0])
            dp[0][0] = 1;
        
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(t[i] == s[j])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
            
        }
        
        return dp[m-1][n-1];
        
    }
};