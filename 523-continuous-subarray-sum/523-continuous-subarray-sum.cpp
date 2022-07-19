

// My solution

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==1)
            return false;
        
       unordered_set<int> st;
        int pre_sum = 0;
        int pre = 0;
        
        for(int i=0;i<n;i++)
        {
            pre_sum += nums[i];
            
            int modk = pre_sum % k;

            
            if(st.count(modk))
                return true;
            st.insert(pre);
            pre = modk;
        }
        
        return false;
        
    }
};