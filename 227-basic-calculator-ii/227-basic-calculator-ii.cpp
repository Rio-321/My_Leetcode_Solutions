class Solution {
public:
    int calculate(string s) {
            
        s = s + "+0+0";
        int res = 0;
        int prev = 0;
        char sign = '+';
        int curr = 0;
        
        cout<<s<<"\n";
        
        for(auto c:s)
        {  
             if(c==' ') continue;
          
            if(isdigit(c))
            {
                curr = curr*10 + (c-'0');
            }
            else
            {
                if(sign=='*')
                {
                    prev = prev*curr;
                    curr=0;
                    sign = c;
                }
                else if(sign=='/')
                {
                    prev = prev/curr;
                    curr=0;
                    sign = c;
                }
                else 
                {
                    if(sign=='-')
                    {
                       res =  res + prev;
                        prev = -curr;
                    } 
                    else if(sign=='+')
                    {
                        res = res + prev;
                        prev = curr;
                    }

                    curr = 0;
                    sign = c;
                }
            }
        }
        
        res = res + prev;
        
        return res;
        
    }
    
    // https://leetcode.com/problems/basic-calculator-ii/discuss/1646099/C%2B%2BPython-Simple-Solutions-w-Explanation-or-Postfix-%2B-Stack-%2B-Without-Stack
};