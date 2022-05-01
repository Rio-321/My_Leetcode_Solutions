class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
      int n = nums.size();
      vector<int> dp(n);
        
      int res = 0;
      unordered_map<int,int> mp;
        
        if(nums[0]%2==1)
        {
            dp[0] = 1;
            
            if(k==1)
                res++;
            mp[1]++;
        }  
        else
        {
            dp[0] = 0;
            mp[0]++;
        }
            
        
      
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2==1)
                dp[i] = dp[i-1]+1;
            else
                dp[i] = dp[i-1];
            
            if(dp[i]==k)
                res++;
            
            if(mp.find(dp[i]-k) != mp.end())
            {
                res = res + mp[dp[i]-k];
            }
            
            mp[dp[i]]++;
            
            
        }
        
        return res;
        
    }
};