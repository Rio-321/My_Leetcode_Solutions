class Solution {
public:
    double f(double x, long long n)
    {
        if(n==0) return 1.0;
        if(n==1) return x;
        
        if(n%2==0)
            return f(x*x,n/2);
        else
            return x*f(x,n-1);
    }
    
    double myPow(double x, int n) {
        
        long long num = n;
        // if(num==0) return 1;
        
        if(num<0)
        {
           num = -1*num;
            x = 1/x;
        }
                
        
        return f(x, num);
        
        
    }
};