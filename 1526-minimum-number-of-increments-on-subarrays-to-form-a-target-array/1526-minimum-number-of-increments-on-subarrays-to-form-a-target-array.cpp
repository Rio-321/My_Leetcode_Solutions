class Solution {
public:

    int minNumberOperations(vector<int>& vec) 
    {
        
        int n = vec.size();
        
        stack<int> st;
        st.push(vec[n-1]);
        int ans = vec[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
             if(vec[i] > st.top())
                  ans = ans + (vec[i] - st.top());
            
            st.push(vec[i]);
        }
        
        
        return ans;
    }
};