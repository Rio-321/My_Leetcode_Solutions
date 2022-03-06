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
        int curr,f=dp[0],s=dp[1];
        
        for(int i=2;i<n;i++)
        {  
            curr = max_num + nums[i];
            max_num = max(max_num, s);
            f = s;
            s = curr;
            
        }
        
        // for(int x:dp)
        //     cout<<x<<" ";
        
        // return max(dp[n-2], dp[n-1]);
        return max(f,s);        
    }
};