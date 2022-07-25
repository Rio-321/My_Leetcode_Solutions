// The time complexity of this brute force approach is O(3^(max(m,n)) and space complexity is O(max(m,n)) where m and n are the length of pattern and string respectively.

class Solution {
public:
    
    vector<vector<int>> dp;
    bool helper(string s, string p, int i, int j)
    {
        if(j == p.size())
            if(i == s.size())
                return true;
            else 
                return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        bool first = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        
        if(j+1 < p.size() && p[j+1] == '*')
        {
                if(helper(s, p, i, j+2))
                    dp[i][j] =  true;
                else
                {
                    if(first == true)
                        dp[i][j] =   helper(s,p,i+1,j);
                    else
                        dp[i][j] =  false;
                }
        }
        else
        {
            if(first == true)
               dp[i][j] =  helper(s, p, i+1, j+1);
            else
                dp[i][j] =  false;
        }
        
        return dp[i][j];
        
    }
    
    
    bool isMatch(string s, string p) {
        
        dp = vector<vector<int>>(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(s,p,0,0);
    }
};