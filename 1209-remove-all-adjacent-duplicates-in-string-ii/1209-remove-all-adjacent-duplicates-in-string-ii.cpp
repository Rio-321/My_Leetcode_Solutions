class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        string res = "";
        stack<pair<char, int>> st;
        
        for(int i=0;i<s.length();i++)
        {
             if(!st.empty() && s[i] == st.top().first)
            {
                pair<char, int> removed = st.top();
                st.pop();
                 
                 if(removed.second+1 < k)
                    st.push({s[i], removed.second+1});
                   
            }
            else
            {
                st.push({s[i], 1});
            }
            
        }
        
       while(!st.empty())
       {
           res = string(st.top().second, st.top().first) + res;
           st.pop();
       }
        
        return res;
        
    }
};