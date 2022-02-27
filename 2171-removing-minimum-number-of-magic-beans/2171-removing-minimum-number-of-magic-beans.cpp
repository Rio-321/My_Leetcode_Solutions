class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        int n = beans.size();
        // vector<long long> pre_sum(n);
        // vector<long long> suff_sum(n);
        
        
        sort(beans.begin(), beans.end());
        
        long long sum = 0;
        
        for(int i=0;i<n;i++)
            sum = sum + beans[i];
        
        long long r = n;
        long long res = LLONG_MIN;
        
        
        for(int i=0;i<n;i++)
        { 
            long long p = r*beans[i];
            // cout<<p<<" ";
            
            res = max(res, p);
            r--;
        }
        
        res = sum - res;
                      
        return res;
    }
};