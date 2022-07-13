class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();
        vector<int> pre(n,0);
        vector<int> post(n,0);
        
        for(int i=0;i<n;i++)
        {
            pre[i] = (i>0) ? pre[i-1] : 0;
            
            if(grumpy[i]==0)
            {
                pre[i] = pre[i] + customers[i]; 
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            post[i] = (i < n-1 ) ? post[i+1] : 0;
            
            if(grumpy[i] == 0)
            {
                post[i] = post[i] + customers[i];
            }
        }
        
        int l = 0, r = 0;
        int res = 0;
        int curr = 0;
        
        while(r < n)
        {
            // if(grumpy[r]==0)
                curr = curr + customers[r];
            
                
            if(r-l+1 == minutes)
            {
                int ans = curr + ((l > 0) ? pre[l-1] : 0) + ((r < n-1) ? post[r+1] : 0);
                res = max(res, ans);
                
                // if(grumpy[l] == 0)
                    curr = curr - customers[l];
                l++;
            }
            r++;
        }
        
        return res;
    }
};