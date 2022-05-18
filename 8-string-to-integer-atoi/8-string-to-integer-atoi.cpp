class Solution {
public:
    int myAtoi(string s) {
    
        int res = 0;
        int sign = 1;
        int i=0;
        
        while(s[i]==' ') i++;
        
        if(s[i]=='+' ||s[i]=='-')
        {
           if(s[i]=='-')
                sign = -1;
            
            i++;
        }

        while(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            if(res>INT_MAX/10 || res==INT_MAX/10 && s[i]-'0'>7)
                if(sign == 1) return INT_MAX;
            else
                return INT_MIN;
            
            res = res*10 + (s[i]-'0');
            i++;
        }
    
        res = res*sign;
        
        return res;
    }
};