class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // BEST SOLUTION
        // https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/775798/c%2B%2B-Four-Solution-or-O-(N*N)-to-greater-O(N)-or-Explain-All
        
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