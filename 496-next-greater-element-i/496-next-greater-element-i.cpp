class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int,int> mp;
        
         stack<int> st;
         vector<int> res(nums2.size());
         
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums2[st.top()]<nums2[i])
                st.pop();
            
            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            
            st.push(i);
            mp[nums2[i]] = i;
        }
        
        vector<int> ans;
        
        for(auto x:nums1)
        {
            if(res[mp[x]]==-1)
                ans.push_back(-1);
            else
                ans.push_back(nums2[res[mp[x]]]);
                
        }
        
        return ans;
    }
};