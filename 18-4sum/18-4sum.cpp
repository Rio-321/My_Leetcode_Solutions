class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        
        for(int i=0;i<n-3;i++)
        { 
            sum = 0;
            
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
             // sum = nums[i];
            
            for(int j=i+1;j<n-2;j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                
                
                
                int l = j+1, r = n-1;
                while(l < r)
                {
                    
                    if(l>j+1 && nums[l]==nums[l-1])
                    {
                        l++;
                        continue; 
                    }
                    
                    long long sum =  nums[i] + nums[j];
                    // sum +=  nums[j];
                    sum +=  nums[l];
                    sum += nums[r];
                    
                    if(sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum > target)
                    {
                        r--;
                    }
                    else
                        l++;
                }
            }
        } 
        return res;
        
        
    }
};