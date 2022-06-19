class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        long long res = 0;
        long long ind = s.length();
        long long prev = s.length();
        unsigned long long pow = 1;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(res+pow>k)break;
            if(s[i]=='1')
            {
                res = res + pow;
                ind = i;
                if(res>k)
                {
                    ind = prev;
                    break;
                }
                prev = i;
            }
            pow = pow<<1;
        }
        

        if(ind==0)
        {
            return s.length();
        }
        
        
        long long cnt = 0;
        // cout<<ind<<"\n";
        
        for(int i=0;i<ind;i++)
        {
            if(s[i]=='0')
                cnt++;
        }
        
        cout<<cnt<<"\n";
        
        long long diff = (s.length()-ind);
        
        // cout<<diff<<"\n";
        
        
        // cout<<cnt<<" ";
        
        return (cnt + diff);
    }
};