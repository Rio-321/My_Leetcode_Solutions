class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int zeroPosition = -1;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                zeroPosition = i;
                break;
            }
                
        }
        
        if(zeroPosition == -1 || zeroPosition == n-1)
            return;
        
        
        for(int i=0;i<n;i++)
        {
            if( i > zeroPosition && nums[i] != 0)
            {
                swap(nums[i], nums[zeroPosition]);
                zeroPosition++;
            }
        }
        
        return;
    }
};