class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> dp(n,0);
        vector<int> st;
        for(int i=0;i<n;i++)
        {
              while(!st.empty() && heights[st.back()]>=heights[i])
                  st.pop_back();
            
            if(st.empty())
                dp[i] = i+1;
            else
                dp[i] = i-st.back();
            
            st.push_back(i);
        }
        
//                 for(auto x:dp)
//             cout<<x<<" ";
        
//         cout<<"\n";
        

        
        st.clear();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.back()]>=heights[i])
                st.pop_back();
            
            if(st.empty())
                dp[i] = dp[i] + n-1-i;
            else
                dp[i] = dp[i] + st.back()-i-1;
            
            st.push_back(i);
        }
        
        int res = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            res = max(res, dp[i]*heights[i]);
        }
        
        return res;
        
        
    }
};