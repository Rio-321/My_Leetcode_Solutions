class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        unordered_map<int, int> mp;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {  
            if(mp.find(nums[i])!=mp.end())
            {
                res.push_back(mp[nums[i]]);
                res.push_back(i);
                break;
            }
            else
                mp[target-nums[i]] = i; 
             
        }
        
        
        return res;
           
        
        
    }
};