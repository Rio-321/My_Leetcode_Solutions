class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int n = tokens.size();
        for(int i=0;i<n;i++)
        {
            string temp1 = tokens[i];
            char temp = tokens[i][0];
            
            if(temp1.size() == 1 && (temp == '+' || temp == '-' || temp == '*'|| temp == '/'))
            {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                
                switch(temp)
                {
                    case '+':
                        st.push(num1+num2);
                        break;
                        
                    case '-':
                        st.push(num1-num2);
                        break;
                        
                    case '*':
                        st.push(num1*num2);
                        break;
                        
                    case '/':
                        st.push(num1/num2);
                        break;
                }
            }
            else
            {
                int num = stoi(temp1);
                st.push(num);
            }
        }
        
        return st.top();
    }
};