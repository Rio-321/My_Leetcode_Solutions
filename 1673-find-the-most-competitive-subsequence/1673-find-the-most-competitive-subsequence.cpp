class Solution {
public:
    // https://leetcode.com/problems/find-the-most-competitive-subsequence/
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        vector<int> stack;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            while(!stack.empty() && stack.back() > nums[i] && (stack.size() - 1 + n - i >= k) )
                  stack.pop_back();
            
            if(stack.size() < k)
                stack.push_back(nums[i]);
        }
        
        return stack;
        
    }
};