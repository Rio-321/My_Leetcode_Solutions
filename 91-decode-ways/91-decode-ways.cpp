class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
         vector<int> dp(n,0);
        
        
        if(s[0]>='1' && s[0]<='9')
                dp[0] = 1;
         
         
        // cout<<dp[0]<<" ";
        
        for(int i=1;i<n;i++)
        {
             if(s[i]>='1' && s[i]<='9')
                 dp[i] = dp[i-1];
            
             if(i>=1)
             {
                 string str = "";
                 str.push_back(s[i-1]);
                 str.push_back(s[i]);
                 int num = stoi(str);
                 // cout<<num<<" ";
                 if(num>=10 && num<=26)
                     dp[i] = (i==1) ? 1 + dp[i] : dp[i-2] + dp[i];
                 
             }
            
            // cout<<dp[i]<<" ";
             
        }
        
        
        
        
        return dp[n-1];
            
    }
};