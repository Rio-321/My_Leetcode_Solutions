class Solution {
public:
    int jump(vector<int>& nums) {
        
        
        
        int n = nums.size();
        
        if(n == 1) return 0;
        
        int maxi = nums[0];
        int p = maxi;
        
        if(maxi >= n-1)
            return 1;
        
        int i=1;
        int ans = 1;
        
        while(i < n)
        {
            maxi = max(maxi, nums[i]+i);
            
            if(maxi >= n-1)
                return ans+1;
            
            if(i == p)
            {
                p = maxi;
                ans++;
            }
            
            i++;
        }
        
        return ans;
    }
};