class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        // https://www.youtube.com/watch?v=XPmA-dkw7qM
        
        // More Optimal solution
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int prev = 0;
        
        for(int i=1;i<n;i++)
        {
            ans = ans + (nums[i]-nums[i-1])*(n-i);
            // prev = prev +  nums[i]-nums[i-1];
        }
        
        return ans;
    }
};