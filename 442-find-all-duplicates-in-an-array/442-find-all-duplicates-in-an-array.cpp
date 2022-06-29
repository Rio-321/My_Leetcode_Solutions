class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // My solution
        set<int> st;
        
        vector<int> res;
        
        for(auto x:nums)  //O(n)
        {
            if(st.find(x) != st.end())  // log(n)
                 res.push_back(x);
            else
                st.insert(x);
        }
        
        
        return res;
    }
};