class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return;
        
        int i = n-2;
        int ind = -1;
        
        while(i>=0)
        {
            if(nums[i]<nums[i+1]) 
            {
                ind = i;
                break;
            }
            i--;
            
        }
        
        
        int low = i+1,high = n-1;
        int ans = -1;
        
//         while(low<=high && ind!=-1)
//         {
//             int mid = (low+high)/2;
            
//             if(nums[mid]>=nums[ind])
//             {
//                 ans = mid;
//                 low = mid+1;
//             }
//             else
//                 high = mid -1;
//         }
        
//         if(ans!=-1)
//         swap(nums[i], nums[ans]);
        
            
        i = n-1;
        
        for(i;i>=0 && ind!=-1;i--)
        {
            if(nums[i]>nums[ind])
            {
                swap(nums[ind], nums[i]);
                break;
            }
        }
        
        int l = ind+1, h = n-1;
        while(l<h)
        {
            swap(nums[l++], nums[h--]);
        }
        
        
        return;
    }
};