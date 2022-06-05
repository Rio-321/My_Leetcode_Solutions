class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        
        int i=0;
        reverse(s.begin(), s.end());
        
        while(i<s.length())
        {
            if(s[i]!=' ')
            { 
                int start = i;
                // string temp = "";
                while(i<s.length() && s[i]!=' ')
                {
                    // temp = temp + s[i];
                    // temp.push_back(s[i]);
                    i++;
                }
                
                reverse(s.begin()+start, s.begin()+i);
                
                // cout<<temp<<"\n";
                    
                // st.push(temp);
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

                
                // i++;
            }  
        }
        
        string res = "";
//         while(!st.empty())
//         {
//             string curr_str =  st.top();
//             st.pop();
//             res = res + curr_str + " ";
//         }
        
//         res.pop_back();
        
        // cout<<s;
        
        return s;
    }
};