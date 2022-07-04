class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        //My Approach
        // int zero = -1, one = -1, two = -1;
        
        int low = 0, high = nums.size()-1;
        int mid = 0;
        
        while(mid<=high)
        {
             if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
                continue;
            }
            
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
                continue;
            }
            
            if(nums[mid] == 1)
                mid++;
        }
        
        
    }
};