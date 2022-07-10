class Solution {
public:
    string addBinary(string a, string b) {
        
        int len1 = a.length();
        int len2 = b.length();
        
        int maxi = max(len1, len2);
        
        a = string(maxi - len1, '0') + a ; 
        b = string(maxi-len2, '0') + b;
        
        cout<<a<<"\n"<<b<<"\n";
        
        int rem = 0;
        string ans;
        
        int num = 0;
        
        for(int i=maxi-1;i>=0;i--)
        {
            if(a[i]=='1' && b[i]=='1')
            {
               num = 10 + rem; 
            }
            else if(a[i] == '0' && b[i]=='0')
            {
                num = rem;
            }
            else
            {
                if(rem == 0)
                    num = 1;
                else
                    num = 10;
            }
            
            ans = char((num%10) + '0') + ans;
            
            rem = num/10;
        }
        
        if(rem == 1)
            ans = '1' + ans;
        
        return ans;
        
        
        
    }
};