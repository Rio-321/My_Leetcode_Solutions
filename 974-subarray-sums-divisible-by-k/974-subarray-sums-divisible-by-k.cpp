class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0, pre_sum = 0;
        map<int,int> mp;
    
        
        for(int i=0;i<n;i++)
        {
            pre_sum += (nums[i]%k + k);
            
            int modk = pre_sum % k;
            
            
            if(modk == 0)
            {
                count++;
                if(mp.count(0))
                    count += mp[0];
            }
            else
            {
                if(mp.count(modk))
                    count += mp[modk];
            }
            
            mp[modk]++;
        }
        
        return count;
    }
};