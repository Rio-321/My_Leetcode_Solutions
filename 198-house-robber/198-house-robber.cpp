class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        // vector<int> dp(n);
        
        int curr,f=nums[0];
        
        if(n==1) return f;
        
        int s=nums[1];
        if(n==2) return max(f, s);
        
        // dp[0] = nums[0];
        // dp[1] = max(nums[1],nums[0]);
        
        
        int max_num = nums[0];
        
        
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