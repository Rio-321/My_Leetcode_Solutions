class Solution {
public:
    
    // https://www.youtube.com/watch?v=mgzcjQ1x9Mw
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int zeroPosition = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] != 0)
            {
                nums[zeroPosition++] = nums[i];
            }    
        }
        
        while(zeroPosition < n)
            nums[zeroPosition++] = 0;
        
        return;
    }
};