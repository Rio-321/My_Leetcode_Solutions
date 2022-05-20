class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);      
        
        
        for(int i=0;i<n;i++)
            prefix[i] = (i>0) ? prefix[i-1]*nums[i] : 1*nums[i];
        
        for(int i=n-1;i>=0;i--)
            suffix[i] = (i<n-1) ? suffix[i+1]*nums[i] : 1*nums[i];
            
            
        for(int i=0;i<n;i++)
        {
            if(i==0)
                nums[i] = suffix[i+1];
            else if(i==n-1)
                nums[i] = prefix[i-1];
            else
                nums[i] = prefix[i-1]*suffix[i+1];
        }
        
        
        return nums;
            
        
        
    }
};