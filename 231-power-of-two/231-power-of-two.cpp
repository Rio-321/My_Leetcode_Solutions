class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)
            return false;
        
        // cout<< ((n)&(n-1)) <<"\n";
        
       return ( ((n)&(n-1)) == 0);
    }
};