class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int count = 0;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            if(freq.find(nums[i])!=freq.end())
                count += freq[nums[i]];
            
            freq[nums[i]]++;
        }
        
        return count;
        
    }
};