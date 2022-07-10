class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        // https://www.youtube.com/watch?v=XPmA-dkw7qM
        
        // Most Optimal solution
        int n = nums.size();
        
        int ans = 0;
        
        int mini = *min_element(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++)
        {
            ans = ans + (nums[i]-mini);
            // prev = prev +  nums[i]-nums[i-1];
        }
        
        return ans;
    }
};