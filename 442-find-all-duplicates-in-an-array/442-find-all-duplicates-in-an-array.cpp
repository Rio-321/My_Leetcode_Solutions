class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // My solution
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
        {
            int ind = abs(nums[i])-1;
            if(nums[ind] < 0)
                res.push_back(abs(nums[i]));
            else
                nums[ind] = -1 * nums[ind];
        }
        
        return res;
    }
};