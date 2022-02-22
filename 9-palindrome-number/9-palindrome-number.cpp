class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        if(x<10)
            return true;
        
        // int digits = floor(log10(x) + 1);
        
        string str = to_string(x);
        // cout<<str;
        
        int n = str.length();
        for(int i=0;i<n/2;i++)
        {
            if(str[i]!=str[n-1-i])
                return false;
        }
        
        return true;
        
    }
};