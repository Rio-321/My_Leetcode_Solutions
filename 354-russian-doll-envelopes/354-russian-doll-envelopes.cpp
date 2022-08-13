 bool mycmp(const vector<int> &a, const vector<int> &b)
    {
        
        if(a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    }

class Solution {
public:
    
   
    
    int ceil_ind(vector<int> &dp, int x, int len)
    {
        int l = 0, r = len-1;
        int ans = len-1;
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            
            if(dp[mid] == x)
                return mid;
            
            if(dp[mid] > x)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        
        return ans;
        
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), mycmp);
        
        vector<int> dp(n, 0);
        dp[0] = envelopes[0][1];
        int len = 1;
        
        for(int i=1;i<n;i++)
        {
            
            if(envelopes[i][1] > dp[len-1])
            {
                dp[len] = envelopes[i][1];
                len++;
            }
            else
            {
                int ind = ceil_ind(dp, envelopes[i][1],len);
                dp[ind] = envelopes[i][1];
            }
        }
        
        return len;
    }
};