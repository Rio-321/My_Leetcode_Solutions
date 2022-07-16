class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        // for(int i=0;i<n;i++)
        //     nums[i] -= target;
        
        sort(nums.begin(), nums.end());
        
        int ans = 1e9;
        
        for(int i=0;i<n-2;i++)
        {
           int l = i+1, r = n-1;
            while(l < r)
            {
                long long sum = nums[i] + nums[l] + nums[r];
                
                if(sum == target)
                    return sum;
                
                if(abs(sum-target) <= abs(ans-target))
                    ans = sum;
                   
                 if(sum > target) 
                     r--;
                else 
                    l++;
            }
        }
        
        return ans;
    }
};