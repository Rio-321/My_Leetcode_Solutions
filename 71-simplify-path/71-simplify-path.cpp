class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        string ANS = "/";
        stack<string> st;
        
        int n = path.length();
        if(n==1) return ANS;
        
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
        
        res.clear();
        
        
        while(!st.empty())
        {
            string curr = st.top();
            st.pop();
            res.push_back(curr);
            // res.push_back("/");
        }
        
        reverse(res.begin(),res.end());
        
        // for(auto x:res)
        //     cout<<x;
        
       for(auto x:res)
       {
           ANS +=(x + "/");
       }
        
        if(ANS.length()>1)
        ANS.pop_back();
           
        
        return ANS;
        
    }
        
   
};