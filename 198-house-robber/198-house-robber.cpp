class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n);
        
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        
        int max_num = dp[0];
        
        for(int i=2;i<n;i++)
        {  
            dp[i] = max_num + nums[i];
            max_num = max(max_num, dp[i-1]);
            
        }
        
        for(int x:dp)
            cout<<x<<" ";
        
        return max(dp[n-2], dp[n-1]);
        
    }
};