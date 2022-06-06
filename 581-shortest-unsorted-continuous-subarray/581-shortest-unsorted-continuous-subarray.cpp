class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int right = -1;
        
        int minA = INT_MAX;
        int maxA = INT_MIN;
        
        for(int i=n-1;i>=0;i--)
        {
            if(minA<nums[i])
                left = i;
            
            minA = min(minA, nums[i]);
            
             if(maxA>nums[n-1-i])
                right = n-1-i;
            
            maxA = max(maxA, nums[n-1-i]);
        }
        
//         for(int i=0;i<n;i++)
//         {
//             if(maxA>nums[i])
//                 right = i;
            
//             maxA = max(maxA, nums[i]);
//         }
        
        
   
        int res = right-left+1;
        
        return res;
        
        
        
       }
};