class Solution {
public:
    int reverse(int x) {
        
        
//         // MY SOLUTION
//         if(x == INT_MIN)
//             return 0;
        
//         int sign  = 1;
//         if(x < 0)
//             sign  = -1;
        
//         x = abs(x);
        
//         int res = 0;
        
        
//         while(x>0)
//         {   
//             if(res > INT_MAX/10)
//                 return 0;
            
//             res = res*10 + x%10;
//             x = x/10;
//         }
        
//         return sign * res;
//     }
    
    // OPTIMAL SOLUTION
        
        int y  = 0;
        while(x)
        {
            if(y > INT_MAX/10 || y < INT_MIN/10)
                return 0;
            
            y = y*10 + x%10;
            x = x/10;
        }
    
      return y;
    }
};