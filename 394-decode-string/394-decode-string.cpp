class Solution {
public:
    string decoded_string(string &s, int &i)
    {
        int num = 0;
        string ans = "";
        while(isdigit(s[i]))
        {
            num = num*10 + (s[i]-'0');
            i++;
        }
        
        if(s[i]=='[')
            i++;
        
        while(i<s.length() && s[i]!=']')
        {  
            if(isdigit(s[i]))
            {
                string temp2 = decoded_string(s,i);
                ans = ans + temp2;
            }
            else if(isalpha(s[i]))
                ans = ans + s[i];
 
            i++; 
        }
        string temp = ans;
        
        for(int j=1;j<num;j++)
            ans += temp;
        
        
        return ans;
          
    }
    
    string decodeString(string s) {
                
        int n = s.length();
        string ans = "";
        int i=0;
        while(i<s.length())
        {   
            if(isdigit(s[i]))
               {
                   string temp1 = decoded_string(s,i);
                   ans = ans+temp1;
               }
               else if(isalpha(s[i]))
                  ans = ans + s[i];
               
             i++;
         }
           
        return ans;
    }
    
    
               
};