class Solution {
public:
    
    void func(vector<int> &nums, int sum, int l, int h, vector<vector<int>> &ans)
    {
        int res = 0;
        
        int i = l,j=h;
        
        while(i<j)
        {
            if(i>l && nums[i]==nums[i-1])
                i++;
            else if(j<h && nums[j]==nums[j+1])
                j--;
            else
            {
                 res = nums[i]+nums[j];
            
            if(res==sum)
            {
                ans.push_back({nums[l-1], nums[i],nums[j]});
                i++;
                j--;
            }
            else if(res<sum)
            {
                i++;
            }
            else
                j--;
            }
           
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
      for(int i=0;i<n;i++)
      {
          if(i>0 && nums[i-1]==nums[i])
              continue;
          
          if(nums[i]>0)
              break;
          
          func(nums,0-nums[i],i+1,n-1,ans);
      }
        
        return ans;
    }
};