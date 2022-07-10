class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int prev = 0;
        
        for(int i=1;i<n;i++)
        {
            ans = ans + prev + (nums[i]-nums[i-1]);
            prev = prev +  nums[i]-nums[i-1];
        }
        
        return ans;
    }
};