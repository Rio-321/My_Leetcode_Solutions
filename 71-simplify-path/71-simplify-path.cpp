class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        string ANS;
        stack<string> st;
        
        int n = path.length();
        
        int i = 0;
        for(;i<n;)
        {    
            if(path[i]=='/')
            {
                while(i<n && path[i]=='/')
                    i++;
            }
            else
            {
                string temp;
                while(i<n && path[i]!='/')
                {
                    temp.push_back(path[i]);
                    i++;
                }
                res.push_back(temp); 
            }
        }
        
        
        for(auto x:res)
        {
            if(x == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(x ==".")
            {
                continue;
            }
            else
            {
                st.push(x);
            }
        }
        

        
        while(!st.empty())
        {
            string curr = st.top();
            ANS = "/" +  curr + ANS;
            st.pop();
        }
        
        if(ANS.length()==0)
           return "/";
           
        return ANS;
        
    }
        
   
};