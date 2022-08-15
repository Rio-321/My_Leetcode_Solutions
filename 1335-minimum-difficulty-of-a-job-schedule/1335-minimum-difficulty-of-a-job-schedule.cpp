class Solution {
public:
    
    int helper(vector<int> &arr, int ind, int d, vector<vector<int>> &dp)
    {
        int n = arr.size();
        if(ind == n && d == 0)
            return 0;
        
        if(ind == n || d == 0) return -1;
        
        if(dp[ind][d] != -1)
            return dp[ind][d];
        
        int maxa = INT_MIN;
        int ans = INT_MAX;
        for(int i = ind; i<n;i++)
        {
            maxa = max(maxa, arr[i]);
            int next = helper(arr, i+1,d-1, dp);
            if(next != -1)
               ans = min(ans, maxa + next); 
        }
        
        if(ans == INT_MAX)
            return dp[ind][d] = -1;
        
        return dp[ind][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        
      return  helper(jobDifficulty, 0, d, dp);
    }
};