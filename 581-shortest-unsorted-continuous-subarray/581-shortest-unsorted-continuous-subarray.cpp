class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp;
            for(auto x:nums)
                temp.push_back(x);
           
        sort(temp.begin(), temp.end());
        
        int left = 0;
        int right = -1;
        
        for(int i=0;i<n;i++)
        {
            if(temp[i]!=nums[i])
            {
                left = i;
                break;
            }
            
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(temp[i]!=nums[i])
            {
                right = i;
                break;
            }
        }
    
        int res = right-left+1;
        
        return res;
        
        
        
       }
};