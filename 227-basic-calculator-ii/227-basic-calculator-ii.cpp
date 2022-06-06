class Solution {
public:
    int calculate(string s) {
        
        if(s.length()==0) return 0;
        char oper = '+';
        stack<int> st;
        int curr;
        int res = 0;
        
        int i=0;
        while(i<s.length())
        {  
            int num = 0;
            if(isdigit(s[i]))
            {
                while(i<s.length() && isdigit(s[i]))
                {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                
                if(oper=='*')
                {
                    curr = st.top()*num;
                    st.pop();
                    st.push(curr);
                }
                else if(oper=='/')
                {
                    curr = st.top()/num;
                    st.pop();
                    st.push(curr);
                }
                else if(oper=='-')
                {
                    curr = -1*num;
                    st.push(curr);
                }
                else
                    st.push(num);
                
                cout<<num<<"\n";
            }
           
            else
            {
                if(s[i]=='+' || s[i]=='/' || s[i]=='*' || s[i]=='-')
                    oper = s[i];
                
               i++; 
            }
                
        }
        
        
        while(!st.empty())
        {
            res =  res + st.top();
            st.pop();
        }
        
        
        return res;
        
        
    }
};