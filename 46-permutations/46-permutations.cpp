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
         
        All_permutations(nums,0,nums.size()-1);
        
        return ans;
        
    }
};