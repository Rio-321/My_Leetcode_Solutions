class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> max_till(n);
        vector<int> min_till(n);
        
        int max_elm = 0;
        int min_elm = 1e6;
        
        for(int i=0;i<n;i++)
        {
            max_elm = max(max_elm, nums[i]);
            max_till[i] = max_elm;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            min_elm = min(min_elm, nums[i]);
            min_till[i] = min_elm;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(max_till[i] <= min_till[i+1])
                return i+1;
        }
        
        return -1;
    }
};