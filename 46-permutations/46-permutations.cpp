class Solution {
public:
    
    vector<vector<int>> ans;
    
    void All_permutations(vector<int> nums,int l,int r)
    {
        if(l==r)
        {
            ans.push_back(nums);
            return;
        }
        else
        {
            for(int i=l;i<=r;i++)
            {
                swap(nums[i],nums[l]);
                All_permutations(nums,l+1,r);
                swap(nums[i],nums[l]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         
        int n = nums.size()-1;
        if(n==0)
        {
            ans.push_back(nums);
            return ans;
        }
        
        All_permutations(nums,0,n);
        return ans;
        
    }
};