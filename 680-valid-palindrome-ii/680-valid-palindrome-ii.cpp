class Solution {
public:
    
    bool is_palindrome(string s, int l, int h)
    {   
        while(l<h)
        {
            if(s[l]!=s[h])
                return false;
            
            l++;
            h--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int n = s.length();
        int l=0,h=n-1;
        
        while(l<h)
        {
            if(s[l]!=s[h])
            {
               if(is_palindrome(s,l+1,h) || is_palindrome(s,l,h-1))
                   return true;
                else
                    return false;
            }
            l++;
            h--;
        }
        
        return true;
        
    }
};