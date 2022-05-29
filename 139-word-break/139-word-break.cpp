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
            // cout<<temp<<"\n";
            if((st.find(temp)!=st.end() && i<n && is_possible(s,i+1,st,dp))) // string is in the set
            {  
                if(i<n-1)
                    dp[i+1] = 1;
                return true;
            }                
        }
        
        dp[ind] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        // unordered_set<string> st;
        
        // for(auto x:wordDict)
        //     st.insert(x);
        //OR
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        vector<int> dp(n,-1);
        
        return is_possible(s,0,st,dp);
    }
};