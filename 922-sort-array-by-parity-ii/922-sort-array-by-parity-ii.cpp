class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> even;
        vector<int> odd;
        vector<int> res;
        
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        
        for(int i=0;i<n/2;i++)
        {
            res.push_back(even[i]);
            res.push_back(odd[i]);
        }
        
        return res;
        
        
    }
};