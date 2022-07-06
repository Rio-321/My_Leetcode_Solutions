class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 2) return n;
        
        int k = 2;
        
        int prev = nums[0];
        
        for(int i=2;i<n;i++)
        {
            if(nums[i] != prev)
            {
                prev = nums[i-1];
                nums[k++] = nums[i];
            }
            else
                prev =  nums[i-1];
        }
        
        return k;
    }
};