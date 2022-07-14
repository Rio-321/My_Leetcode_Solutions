class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          // My Solution - 
            // Time - O(n)
            // space - O(1)
        
//           int n = nums.size();
        
//           for(int i=0;i<n;i++)
//           {
//               while(nums[nums[i]-1]  != nums[i])
//               {
//                   swap(nums[i], nums[nums[i]-1]);
//               }
              
//               if(nums[i] != i+1 && nums[nums[i]-1] == nums[i])
//                   return nums[i];
//           }
        
//         return -1;
        

// ************************************binary search solution**************
        
        // Time - O(nlog(n));
        // space - O(1)
        
        int low = 1;
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            // cout<<mid<<"\n";
            
            int cnt = 0;

            for(auto x:nums)
                if(x<=mid)
                    cnt++;
            
            if(cnt>mid)
                high = mid-1;
            else
                low = mid+1;

        }
        
        return low;
    }
};