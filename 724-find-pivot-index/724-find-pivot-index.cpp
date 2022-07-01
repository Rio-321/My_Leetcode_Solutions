class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        
        int leftSum = 0;
        int rightSum = 0;
        
        for(auto x:nums)
            rightSum += x;
        
        for(int i=0;i<n;i++)
        { 
            rightSum  = rightSum -  nums[i];
            if(leftSum == rightSum)
                return i;
            
            leftSum = leftSum + nums[i];
        }
        
        return -1;
        
    }
};