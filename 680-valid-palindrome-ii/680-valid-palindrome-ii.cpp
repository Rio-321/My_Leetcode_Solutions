class Solution {
public:
    
    bool check_palindrome(string &s, int l, int h, int count)
    {
        if(count>1) return false;
        
        while(l<h)
        {
            if(s[l]==s[h])
                l++,h--;
            else
            {
                return (check_palindrome(s,l+1,h,count+1) || check_palindrome(s,l,h-1,count+1));
            }
                
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int n = s.length();
        
        return check_palindrome(s,0,n-1,0);
        
    }
};