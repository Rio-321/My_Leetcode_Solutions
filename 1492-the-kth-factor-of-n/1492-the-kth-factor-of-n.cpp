class Solution {
public:
    
    // if(sqrt(n)*sqrt(n) == n ) factors are odd else are even
    int kthFactor(int n, int k) {
        
        int factor = 1;
        int num = 1;
        
        vector<int> vec;
        
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i == 0)
            {
                if(factor == k)
                    return i;
                
                factor++;
                
                if(n/i != i)
                    vec.push_back(n/i);
            }
        }
        
        for(int i=vec.size()-1; i>=0;i--)
        {
            if(factor == k)
                return vec[i];
            
            factor++;
        }
        
        
        return -1;
    }
};