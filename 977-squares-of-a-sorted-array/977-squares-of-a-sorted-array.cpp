class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n);
        int l = 0, r = n-1;
        int ind = n-1;
        
        while(l <= r)
        {
            if(abs(nums[l]) <= abs(nums[r]))
            {
                ans[ind] = nums[r]*nums[r];
                r--;
            }
            else
            {
                ans[ind] = nums[l]*nums[l];
                l++;
            }
            
            ind--;
        }
        
        // for(int i=0;i<n;i++)
        //     nums[i] = nums[i] * nums[i];
        
        return ans;
        
    }
};