class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        
        int mod = 1e9+7;
        
        vector<int> left_smaller(n,0);
        vector<int> right_smaller(n,0);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            
            if(st.empty())
                left_smaller[i] = 0;
            else
                left_smaller[i] = st.top()+1;
            
            
            st.push(i);
        }
        
        long long sum = 0;
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            
            if(st.empty())
                right_smaller[i] = n-1;
            else
                right_smaller[i] = st.top()-1;
            
            st.push(i);
        }
        
        for(int i=0;i<n;i++)
        {  
            // cout<<left_smaller[i]<<" "<<right_smaller[i]<<"\n";
            long long num = (((i-left_smaller[i]+1)%mod) * ((right_smaller[i]-i+1)%mod))%mod;
            
            sum = sum%mod + (num*((arr[i])%mod))%mod;
        }
        
        return sum;
        
    }
};