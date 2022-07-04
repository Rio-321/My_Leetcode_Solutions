class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        //Optimal Approach
        // [0,low-1] --> 0
        // [low,high] --> 1
        // [high+1, n-1] --> 2
        // mid --> current index
        
        int low = 0, high = nums.size()-1;
        int mid = 0;
        
       while(mid <= high)
       {
           switch (nums[mid]){
                   
               case 1:
                   mid++;
                   break;
               case 2:
                   swap(nums[mid], nums[high]);
                   high--;
                   break;
                        
               case 0:
                    swap(nums[mid], nums[low]);
                    low++;
                    mid++;
                    break;
                    
           }
       }
        
        
    }
};