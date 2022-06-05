class Solution {
public:
    string reverseWords(string s) {
        
        
        int i=0;
        reverse(s.begin(), s.end());
        
        while(i<s.length())
        {
            if(s[i]!=' ')
            { 
                int start = i;
                while(i<s.length() && s[i]!=' ')
                    i++;
                
                reverse(s.begin()+start, s.begin()+i);

            }
            else
            {  
                
                while(i<s.length() && s[i]==' ')
                {
                    if(i>0 && i<s.length()-1 && s[i+1]!=' ')
                    {
                        i++;
                        break;
                    }
                    s.erase(s.begin()+i);
                }

                
            }  
        }
        
        return s;
    }
};