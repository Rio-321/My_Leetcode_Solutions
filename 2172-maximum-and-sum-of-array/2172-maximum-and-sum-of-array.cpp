class Solution {
public:
    int maximumANDSum(vector<int>& v, int k) {
        int n =v.size();
 for(int i=0;i<n;i++)
 {
    int a=v[i];
    int cnt=4;
    vector<int>bit;
    while(a>0 && cnt>0)
    {
        bit.push_back(a%2);
        a=a/2;cnt--;
    }
    int nw=0;
    for(int j=0;j<(int)bit.size();j++)
    nw+=(pow(2,j)*bit[j]);
    v[i]=nw;
 }
 v.resize(2 * k);
    int N = v.size();
    vector<int> dp(1 << N);
    for (int m = 1; m < 1 << N; ++m) {
        int cnt = __builtin_popcount(m), slot = (cnt + 1) / 2; 
        for (int i = 0; i < N; ++i) {
            if (m >> i & 1) { 
                dp[m] = max(dp[m], dp[m ^ (1 << i)] + (slot &v[i]));
            }
        }
    }
    return dp[(1 << N) - 1];
    }
};