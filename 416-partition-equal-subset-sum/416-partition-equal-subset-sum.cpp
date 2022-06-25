class Solution {
public:
    
    bool solve(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
    {  
        
        if(sum == 0)
        {
            dp[n][sum] = true;
            return dp[n][sum]; 
        }
            
        if(n == 0)
        {
            dp[n][sum] = false;
            return dp[n][sum];
        }
        
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        
        bool  notTaken = solve(nums, n-1, sum, dp);
        
        if(nums[n-1] > sum)
        {
            dp[n][sum] = notTaken;
            return dp[n][sum];
        }
            
        else
        {
            dp[n][sum] = notTaken || solve(nums, n-1, sum - nums[n-1], dp);
            return dp[n][sum];
        }
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i];
        
        if(sum % 2 == 1)
            return false;
        
        int sum1 = sum/2;
        
        vector<vector<int>> dp(n+1, vector<int>(sum1 + 1, -1));
        
        return solve(nums,n,sum1, dp);
        
    }
};