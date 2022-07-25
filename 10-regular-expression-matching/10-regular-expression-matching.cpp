// Memoization Solution - 

// The time complexity is now O(mn) and space complexity is O(mn) where m and n are the length of pattern and string respectively.

class Solution {
public:    
    
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
          
        dp[s.size()][p.size()] = 1;
        
        for(int i=0;i<s.size();i++)
            dp[i][p.size()] = 0;
        
        for(int i=s.size();i>=0;i--)
        {
            for(int j=p.size()-1;j>=0;j--)
            {
                
                    bool first = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

                    if(j+1 < p.size() && p[j+1] == '*')
                    {
                            if(dp[i][j+2])
                                dp[i][j] =  1;
                            else
                            {
                                if(first == true)
                                    dp[i][j] =  dp[i+1][j];
                                else
                                    dp[i][j] =  false;
                            }
                    }
                    else
                    {
                        if(first == true)
                           dp[i][j] = dp[i+1][j+1];
                        else
                            dp[i][j] =  false;
                    }

                
            }
        }
        
        return dp[0][0];
    }
};