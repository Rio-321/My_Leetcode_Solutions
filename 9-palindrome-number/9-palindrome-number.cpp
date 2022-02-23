class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        if(x<10)
            return true;
        if(x%10==0 && x!=0)
            return false;
        
        int rev_No = 0;
        
        while(x>rev_No)
        {
            rev_No = rev_No*10 + x%10;
            x = x/10;
        }
        
        if(x==rev_No || x==rev_No/10)  return true;
        else return false;
        
        // int digits = floor(log10(x) + 1);
        
//         string str = to_string(x);
//         // cout<<str;
        
//         int n = str.length();
//         for(int i=0;i<n/2;i++)
//         {
//             if(str[i]!=str[n-1-i])
//                 return false;
//         }
        
        return true;
        
    }
};