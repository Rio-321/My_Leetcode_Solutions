class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long long low = 0,high = abs(dividend);
        long long ans = 0;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            // cout<<mid<<"\n";
            
            if(mid*abs(divisor) == abs(dividend))
            {
                ans = mid;
                break;
            }
                
            
            if(mid*abs(divisor) > abs(dividend))
                high = mid-1;
            else
            {
                low = mid+1;
                ans = mid;
            }
        }
        
        cout<<ans<<"\n";
        
        if((long long)dividend * (long long)divisor < 0 )
            ans = ans *(-1);
        
        cout<<ans;
        
        if(ans>INT_MAX)
            ans = INT_MAX;
        
        if(ans < INT_MIN)
            ans = INT_MIN;
            
        
        return (int)ans;
    }
};