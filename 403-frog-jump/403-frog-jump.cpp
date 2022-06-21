class Solution {
public:
    
    bool DFS(int src, int k, int &target, map<int,int> &st, vector<vector<bool>> &dp)
    {
       
        if(dp[k][st[src]])
            return false;
        
    if(src + k == target || src + k + 1 == target || src + k - 1 == target)
            return true;
        
        dp[k][st[src]] = true;
        
        if(src + k < target && st.find(src + k) != st.end())
            if(DFS(src + k, k, target, st, dp))
                return true;
        
        if(src + k + 1 < target && st.find(src + k + 1) != st.end())
            if(DFS(src + k + 1, k + 1, target, st, dp))
                return true;
        
        if(src + k - 1 < target && st.find(src + k - 1) != st.end() && k!=1)
            if(DFS(src + k - 1, k - 1, target, st, dp))
                return true;
        
        
        return false;
    }
    
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        map<int,int> st;
        for(int i=0;i<stones.size();i++)
            st[stones[i]] = i;
        
        int target = stones[stones.size()-1];
        // return true;
        
        vector<vector<bool>> dp(n+2, vector<bool>(n));
        
        if(stones[1] - stones[0] != 1) return false;
       return DFS(stones[1], 1,target,st,dp);
    }
};