class Solution {
public:
    
    int func(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if( i > j)
            return 0;
        
        int res = INT_MIN;
        for(int k = i; k<=j; k++)
        {
            int cost = func(i, k-1, nums, dp) + nums[i-1]*nums[k]*nums[j+1] + func(k+1, j, nums, dp);
            
            res = max(res,  cost);
        }
        
        dp[i][j] = res;
        return res;
    }
    
    int maxCoins(vector<int>& nums) {
        
        // main point in this question is that you have to see from bottom i.e. which will be the last balloon to burst
        // see striver video
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n = nums.size();
        
        for(auto x:nums)
            cout<<x<<" ";
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(1, n-2, nums, dp);
    }
};