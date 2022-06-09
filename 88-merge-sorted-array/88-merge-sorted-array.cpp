class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> ans;
        int up=0,down=0;
        
        while(up<m && down<n)
        {
            if(nums1[up]==nums2[down])
            {
                ans.push_back(nums1[up++]);
                ans.push_back(nums2[down++]);
            }
            else if(nums1[up]>nums2[down])
            {
                ans.push_back(nums2[down++]);
            }
            else
            {
                ans.push_back(nums1[up++]);
            }
                
        }
        
        while(up<m)
        {
            ans.push_back(nums1[up++]);
        }
        
        while(down<n)
        {
            ans.push_back(nums2[down++]);
        }
        
        for(int i=0;i<ans.size();i++)
            nums1[i] = ans[i];
        
        return;
    }
};