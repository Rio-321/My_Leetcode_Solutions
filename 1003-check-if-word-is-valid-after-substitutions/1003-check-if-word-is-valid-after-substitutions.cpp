class Solution {
public:
    bool isValid(string s) {
        
     
        int n = s.length();
        
        if(s[0]!='a'|| s[n-1]!='c') return false;
        
        vector<char> st;
        
        for(char ch:s)
        {
            if(ch=='c')
            {
                if(st.size()<2 || st[st.size()-1]!='b' || st[st.size()-2]!='a')
                    return false;
                
                st.pop_back();
                st.pop_back();
            }
            else
                st.push_back(ch);
                
        }
        
        if(st.size()==0)
            return true;
        else
            return false;
        
    }
};