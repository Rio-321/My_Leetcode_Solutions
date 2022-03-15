class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        
        if(n%2!=0) return false;
        
        stack<char> pack;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                pack.push(s[i]);
            else
            {  
                if(pack.empty()) return false;
                else
                {
                  if( int(s[i])-int(pack.top()) !=1 && int(s[i])-int(pack.top()) != 2) 
                      return false;
                    else
                        pack.pop();
                      
                }
                
            }
            
        }
        
        if(pack.size()>0)
            return false;
        
        return true;
    }
};