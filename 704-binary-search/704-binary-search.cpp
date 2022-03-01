class Solution {
public:
    
//     int Index_Of(vector<int>& nums, int x, int low, int high)
//     {
//         while(low<=high)
//         {
//             int mid = (low+high)/2;
            
//             if(nums[mid]==x)
//                 return mid;
            
//             if(nums[mid]>x)
//                 high = mid-1;
//             else
//                 low = mid+1;
//         }
        
//         return -1;        
//     }
    
    int search(vector<int>& nums, int target) {
        
        // return Index_Of(nums,target,0,nums.size()-1);
        
        int low = 0,high = nums.size()-1;
        int x = target;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(nums[mid]==x)
                return mid;
            
            if(nums[mid]>x)
                high = mid-1;
            else
                low = mid+1;
        }
        
        return -1;  
        
        
        
        
    }
};