class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0;
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            if(sum == k)
            {
                 count = count + 1; 
                 // mp[sum]++;
                 // continue;
            }
            
            
            if(mp.find(sum-k)!=mp.end())
            {
                count = count + mp[sum-k];
            }
            
            mp[sum]++;
                
        }
        
        return count;
        
    }
};