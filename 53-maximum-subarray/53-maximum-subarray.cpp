class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int max_num = INT_MIN;
        int pre_sum = 0;
        int max_sum = INT_MIN;
        for(int i=0;i<n;i++)
        {
            max_num = max(max_num,nums[i]);
            pre_sum = pre_sum + nums[i];
            max_sum = max(max_sum, pre_sum);
            
            if(pre_sum < 0)
                pre_sum = 0;   
        }
        
        return max(max_sum, max_num);
        
    }
};