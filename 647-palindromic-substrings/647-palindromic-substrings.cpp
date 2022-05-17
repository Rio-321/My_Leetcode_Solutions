class Solution {
public:   
    
    int Count_Palind(string &str,int l, int r,int n)
    {   
        int res = 0;
        while(l>=0 && r<=n-1)
        {
            if(str[l]!=str[r])
                break;
            else
                res++;
            
            l--;
            r++;
        }
        
        return res;
    }
    int countSubstrings(string s) {
      
        int res = 0;
        int n = s.length();
        
        int l,r;
        
        
        for(int i=0;i<n;i++)
        {
            res += Count_Palind(s,i,i,n);
            res += Count_Palind(s,i,i+1,n);
           
        }
        
        
        return res;
    }
};