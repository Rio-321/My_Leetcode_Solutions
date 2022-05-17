class Solution {
public:
    string palin_string(string &str, int l, int r, int n)
    {   
        string res = "";
        while(l>=0 && r<=n-1)
        {
           if(str[l]!=str[r])
               break;
            else
            {
                if(l==r)
                    res.push_back(str[l]);
                else
                {
                    res.push_back(str[r]);
                    string temp = "";
                    temp.push_back(str[l]);
                    res.insert(0,temp);
                }
            }
            
            l--;
            r++;
                
        }
        
        return res;
    }
    string longestPalindrome(string s) {
        
        string res = "";
        
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            string temp = palin_string(s,i,i,n);
            if(temp.length() > res.length())
                res = temp;
            
            string temp1 = palin_string(s,i,i+1,n);
            if(temp1.length() > res.length())
                res = temp1;
        } 
        
        return res;
        
    }
};