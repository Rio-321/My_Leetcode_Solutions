class Solution {
public:    
    int countSubstrings(string s) {
      
        int res = 0;
        int n = s.length();
        
        int l,r;
        
        
        for(int i=0;i<n;i++)
        {
            l = i,r=i;
            while(l>=0 &&r<=n-1)
            {
                if(s[l]!=s[r])
                    break;
                else
                    res++;
                
                l--;
                r++;
            }
            
            l = i,
            r = i+1;
            while(l>=0 && r<=n-1)
            {
                if(s[l]!=s[r])
                    break;
                else
                    res++;
                
                l--;
                r++;
            }
        }
        
        
        return res;
    }
};