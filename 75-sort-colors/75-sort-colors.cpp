class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        //My Approach
        int n = nums.size();
        vector<int> ans(n,-1);
        int zero = -1, one = -1, two = -1;
        
        for(auto x:nums)
        {
            if(x == 2)
            {
               two++;
               nums[two] = 2;
            }
            else if(x == 1)
            {
                two++;
                one++;
                // nums[two] = nums[one];
                swap(nums[one], nums[two]);
                nums[one] = 1;
            }
            else
            {
                zero++;
                one++;
                two++;
                // nums[two] = nums[one];
                swap(nums[two], nums[one]);
                swap(nums[one], nums[zero]);
                // nums[one] = nums[zero];
                nums[zero] = 0;
            }
        }
        
    }
};