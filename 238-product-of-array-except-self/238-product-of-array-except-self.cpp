class Solution {
public:
    
    // Optimal Approach
    // time - O(N);
    // space - O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,1);
        long long pre = 1;
        long long post = 1;
        
        for(int i=0;i<n;i++)
        {
            ans[i] = ans[i] * pre;
            pre = pre * nums[i];
            
            ans[n-1-i] = ans[n-1-i]*post;
            post = post * nums[n-1-i];
        }
        
//         for(int i=n-1;i>=0;i--)
//         {
//             ans[i] = ans[i]*post;
//             post = post * nums[i];
//         }
        
        return ans;
        
        
    }
};