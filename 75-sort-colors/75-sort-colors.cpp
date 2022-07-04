class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        //My Approach
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
                swap(nums[one], nums[two]);
                nums[one] = 1;
            }
            else
            {
                zero++;
                one++;
                two++;
                swap(nums[two], nums[one]);
                swap(nums[one], nums[zero]);
                nums[zero] = 0;
            }
        }
        
    }
};