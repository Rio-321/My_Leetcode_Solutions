class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        
        int i=0;
        
        while(i<s.length())
        {
            if(s[i]!=' ')
            {
                string temp = "";
                while(i<s.length() && s[i]!=' ')
                {
                    temp.push_back(s[i]);
                    i++;
                }
                
                // cout<<temp<<"\n";
                    
                st.push(temp);
            }
            else
            {
                i++;
            }  
        }
        
        string res = "";
        while(!st.empty())
        {
            string curr_str =  st.top();
            st.pop();
            res = res + curr_str + " ";
        }
        
        res.pop_back();
        
        return res;
    }
};