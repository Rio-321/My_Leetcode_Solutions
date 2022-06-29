class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        set<int> st;
        
        vector<int> res;
        
        for(auto x:nums)
        {
            if(st.find(x) != st.end())
                 res.push_back(x);
            else
                st.insert(x);
        }
        
        
        return res;
    }
};