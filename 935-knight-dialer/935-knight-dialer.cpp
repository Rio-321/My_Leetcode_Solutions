class Solution {
    
    int mod = 1e9 + 7;
public:
    int knightDialer(int n) {
        
        if(n==1)
            return 10;
        if(n==2)
            return 20;
        
        vector<long long> vec(10);
        vector<long long> res(10);
        
        for(int i=0;i<10;i++)
            vec[i] = 1;
        
        long long sum = 0;
        
        
        for(int j=1;j<n;j++)
        {
            res[0] = (vec[4]%mod + vec[6]%mod)%mod;
            res[1] = (vec[6]%mod + vec[8]%mod)%mod;
            res[2] = (vec[7]%mod + vec[9]%mod)%mod;
            res[3] = (vec[4]%mod + vec[8]%mod)%mod;
            res[4] = (vec[0]%mod + vec[3]%mod + vec[9]%mod)%mod;
            res[5] = 0;
            res[6] = (vec[0]%mod + vec[1]%mod + vec[7]%mod)%mod;
            res[7] = (vec[2]%mod + vec[6]%mod)%mod;
            res[8] = (vec[1]%mod + vec[3]%mod)%mod;
            res[9] = (vec[2]%mod + vec[4]%mod)%mod;

            vec = res; 
        }
        
        for(int i=0;i<10;i++)
            sum = (sum%mod + res[i]%mod)%mod;
       
        
        
        return sum;
          
        
    }
};