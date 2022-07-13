class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();
        
        int pre = 0, post = 0;
        
        
        for(int i=n-1;i>=0;i--)
        {      
            if(grumpy[i] == 0)
            {
                post = post + customers[i];
            }
        }
        
        int l = 0, r = 0;
        int res = 0;
        int curr = 0;
        
        while(r < n)
        {
            
            curr = curr + customers[r];
            
            if(grumpy[r] == 0)
                post = post - customers[r];
            
                
            if(r-l+1 == minutes)
            {
                int ans = curr + pre + post;
                res = max(res, ans);
                
                curr = curr - customers[l];
                
                if(grumpy[l]==0)
                    pre = pre + customers[l];
                
                l++;
            }
            r++;
        }
        
        return res;
    }
};