class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        int n = beans.size();
        vector<long long> pre_sum(n);
        vector<long long> suff_sum(n);
        
        
        sort(beans.begin(), beans.end());
        
            
        for(int i=0;i<n;i++)
            {
                if(i==0)
                    pre_sum[i] = beans[i];
                else
                    pre_sum[i] = pre_sum[i-1] + beans[i];
            }
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                suff_sum[i] = beans[i];
            else
                suff_sum[i] = suff_sum[i+1]+beans[i];
        }
        
        long long res = LLONG_MAX;
        
        for(int i=0;i<n;i++)
        {
            long long p = pre_sum[i] - beans[i] + suff_sum[i] - (long long)(n)*beans[i] + (long long)(i)*beans[i];
            // cout<<p<<" ";
            res = min(res,p);
        }
        
        // cout<<"\n";
        
        return res;
    }
};