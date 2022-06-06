class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
//         vector<int> temp;
//             for(auto x:nums)
//                 temp.push_back(x);
           
//         sort(temp.begin(), temp.end());
        
        int left = 0;
        int right = -1;
        
        int minA = INT_MAX;
        int maxA = INT_MIN;
        
        for(int i=n-1;i>=0;i--)
        {
            if(minA<nums[i])
                left = i;
            
            minA = min(minA, nums[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(maxA>nums[i])
                right = i;
            
            maxA = max(maxA, nums[i]);
        }
        
        // cout<<left<<" "<<right<<"\n";
        
   
        int res = right-left+1;
        
        return res;
        
        
        
       }
};