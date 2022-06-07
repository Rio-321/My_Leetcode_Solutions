class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return;
        
        int i = n-2;
        int ind = -1;
        
        while(i>=0)
        {
            if(nums[i]<nums[i+1]) //
            {
                ind = i;
                break;
            }
            i--;
            
        }
        
        // cout<<i<<"\n";
            
        i = n-1;
        for(i;i>=0 && ind!=-1;i--)
        {
            if(nums[i]>nums[ind])
            {
                swap(nums[ind], nums[i]);
                break;
            }
        }
        
        int l = ind+1, h = n-1;
        while(l<h)
        {
            swap(nums[l++], nums[h--]);
        }
        
        
        return;
    }
};