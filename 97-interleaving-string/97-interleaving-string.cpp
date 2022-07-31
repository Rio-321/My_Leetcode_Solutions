class Solution {
public:
    
    unordered_map<string, bool> mp;
    // vector<vector<vector<int>>> dp;
    
    bool helper(string s3,string s2, string s1, int i, int f, int s)
    {
        
        if(i == s3.size())
        {
           if(f == s1.size() && s == s2.size())
                 return true;
            else
                return false; 
        }
        
        string key = to_string(f) + "*" + to_string(s) + "*" + to_string(i);
        if(mp.find(key) != mp.end())
            return mp[key];
        
        
        
        // if(dp[i][f][s] != -1)
        //     return dp[i][f][s];
        
        if(f == s1.size())
        {
            if(s3[i] == s2[s])
               return mp[key] =  helper(s3,s2,s1,i+1,f,s+1);
            else
               return mp[key] = false;
                
        }
        
        if(s == s2.size())
        {
            if(s3[i] == s1[f])
                return mp[key] = helper(s3,s2,s1,i+1,f+1,s);
            else
                return mp[key] = false;            
        }
        
        if(s3[i] == s1[f])
            if(helper(s3,s2,s1,i+1,f+1,s))
                return mp[key] = true;
        
        if(s3[i] == s2[s])
            if(helper(s3,s2,s1,i+1,f,s+1))
                return mp[key] = true;
        
     
        
        return mp[key]=false;
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        
        if(c != a+b)
            return false;
        
        
//         dp = vector<vector<vector<int>>> (202, vector<vector<int>>(202, vector<int>(202, -1)));
        
        
        
        if(helper(s3,s2,s1,0,0,0))
            return true;


        return false;
        
        
        
    }
};