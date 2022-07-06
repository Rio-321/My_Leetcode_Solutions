class Solution {
public:
    
    bool is_possible(string s, int ind, unordered_set<string> &st, vector<int> &dp)
    {   
        
        int n = s.length();
        if(ind==n) return true;
        
        if(dp[ind]!=-1) return dp[ind];
        
        
        string temp = "";
        for(int i=ind;i<n;i++)
        {
            temp = temp + s[i];

            if(st.find(temp)!=st.end()) // string is in the set
            {  
                if(is_possible(s,i+1,st,dp))
                    return dp[ind] = true;
            }                
        }
        
        return dp[ind] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
      
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        vector<int> dp(n,-1);
        
        return is_possible(s,0,st,dp);
    }
};