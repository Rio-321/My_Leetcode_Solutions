class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalindrome(string s, int l, int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            
            l++;
            r--;
        }
        return true;
    }
    
    
    
    void palindrome(int index, vector<string> &temp, string &s)
    {
        if(index==s.length())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index; i<s.length(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i-index+1));
                palindrome(i + 1, temp, s);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        
        vector<string> temp;
        palindrome(0, temp, s);
        
        return res;

    }
};