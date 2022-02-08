class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)
            return false;
        
        n = abs(n);
        int p = abs(n-1);
        
        int res = n & p;
        
        // cout<<res;
        
        if( res != 0 )
            return false;
        else
            return true;
    }
};