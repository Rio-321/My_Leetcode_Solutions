class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        int ans = INT_MIN;
        
        // first  element  taken
        
        
        int prev = 0;
        int prev_prev = 0;
        
        prev = nums[0];
        int curr = nums[0];
        
        for(int i=1;i<n-1;i++)
        {
            curr = max(prev, prev_prev + nums[i]);
            
            prev_prev = prev;
            prev = curr;
        }
        
        ans = max(ans, curr);
        
        // first element not taken taken
        
        
        prev_prev = 0;
        prev = nums[1];
        curr = nums[1];
        
        for(int i=2;i<n;i++)
        {
            curr = max(prev, prev_prev+nums[i]);
            
            prev_prev = prev;
            prev = curr;
        }
        
        ans = max(ans, curr);
        
        
        return ans;
        
        
    }
};