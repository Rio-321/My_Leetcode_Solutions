class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long res = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            int maxA = INT_MIN;
            int minA = INT_MAX;
            
            for(int j=i;j>=0;j--)
            {
                maxA = max(maxA, nums[j]);
                minA = min(minA, nums[j]);
                
                res  += (maxA-minA);
            }
        }
        
        return res;                 
    }
};