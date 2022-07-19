// My solution

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return false;
        
        unordered_map<int, int> mp;
        int pre_sum = 0;
        int modk = 0;
        for(int i=0;i<n;i++)
        {
            pre_sum = pre_sum + nums[i];
            modk = pre_sum%k;
            
            if(pre_sum%k==0 && i>0)  return true;
            
            if(mp.find(modk)!=mp.end() && i-mp[modk]>1)
                return true;
            
            if(mp.find(modk)==mp.end())
                mp[modk] = i;
        }
        
       return false;
        
    }
};