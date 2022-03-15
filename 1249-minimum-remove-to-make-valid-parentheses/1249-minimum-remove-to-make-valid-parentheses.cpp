class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        string res = "";
        stack<int> parenth;
        for(int i=0;i<n;i++)
        {  
            if(s[i]=='(') 
                parenth.push(i);
            else if(s[i]==')')
            {  
                if(!parenth.empty())
                    parenth.pop();
                else
                    s[i] = '*';
             
            }
       
        }
        
        // cout<<parenth.size()<<"\n";
        
        while(!parenth.empty())
        {
            s[parenth.top()] = '*';
            {
               parenth.pop(); 
            }
                
        }
        
//        for(int i=0;i<n;i++)
//        {
//            if(s[i]!='*')
//               res = res + s[i];
              
//        }
        
    
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        
        return s;
    }
};