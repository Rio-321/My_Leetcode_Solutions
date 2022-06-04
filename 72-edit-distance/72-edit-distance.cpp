class Solution {
public:
    
    int Minimum_Distance(string &word1, int n1, string &word2, int n2, vector<vector<int>>&dp)
    {  
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        if(n1==0) return dp[n1][n2]=n2;
        if(n2==0) return dp[n1][n2]=n1;
        
        if(word1[n1-1]==word2[n2-1])
            dp[n1][n2] = Minimum_Distance(word1,n1-1,word2,n2-1,dp);
        else
        {
            dp[n1][n2] =  1+ min(Minimum_Distance(word1,n1,word2,n2-1,dp), min(Minimum_Distance(word1,n1-1,word2,n2-1,dp),Minimum_Distance(word1,n1-1,word2,n2,dp)));
        }
        
        return dp[n1][n2];
    }
    
    
    int minDistance(string word1, string word2) {
        
        int n1 = word1.length();
        int n2 = word2.length();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        
        Minimum_Distance(word1,n1,word2,n2,dp);
        
        return dp[n1][n2];
    }
};