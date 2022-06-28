class Solution {
public:
    
    int func(string &s, int &i)
    {
        
        int res = 0;
        int curr = 0, prev = 0;
        char sign  = '+';
        

        
        while(i < s.length())
        {   
            int c = s[i];
            if(c == ' ')
            {
                i++;
                continue;
            }
            
            if(isdigit(c))
            {
                curr = curr*10 + (c-'0');
            }
            else
            { 
                if(c == '(')
                {   
                    i++;
                    curr = func(s,i);
                }
                else if(c == ')')
                {
                    res = res + prev;
                    // i++;
                    // cout<<res<<"\n";
                    return res;
                }
                else
                {
                    if(sign == '+')
                    {
                        res = res + prev;
                        prev = curr;
                        sign = c;
                        curr = 0;
                    }
                    else if(sign == '-')
                    {
                        res = res + prev;
                        prev = -curr;
                        curr = 0;
                        sign = c;
                    }
                }     
                
            }
            
            i++;
        }
        
        res = res + prev;
        
        return res;       
    }

    int calculate(string s) {
        
        for(int j=0;j<s.length();j++)
            if(s[j] == ')')
                s.insert(j,"+"), j++;
        
        s = s + '+';
        
        // cout<<s<<"\n";
                
                
        int i = 0;
        return func(s,i);
        // return 0;
    }
};