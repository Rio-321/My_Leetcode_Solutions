class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        //ANOTHER APPROACH
        int n = nums.size();
        if(n == 1) return true;
        
        int last = n-1;
        
        for(int i=n-2; i>=0;i--)
        {
            if(nums[i]+i >= last)
                last = i;
        }
        
        if(last == 0)
            return true;
        
        return false;
        
    }
};