class Solution {
public:
    int findMin(vector<int>& nums) {
         
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        if(nums[n-1]>nums[0])
            return nums[0];
        
        
        
        
        int res = INT_MAX;
        
        int low = 0,high=n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid]>=nums[0])
            {
                low = mid+1;
            }
            else
            {
                res = min(res,nums[mid]);
                high = mid-1;
            }
                
        }
        
        
        return res;
        
        
    }
};