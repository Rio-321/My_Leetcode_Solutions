class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0) return 0;
        long long low = 1, high = x;
        
        long long res;
        
        while(low<=high)
        {
            long long  mid = (low+high)/2;
            
            long long num = (long long)mid*mid;
            if(num==x) return mid;
            
            if(num>x)
                high = mid-1;
            else
            {
                res = mid;
                low = mid+1; 
            }
                
        }
        
        return res;
        
    }
};