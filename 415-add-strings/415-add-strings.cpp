class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string temp;
        int rem = 0;
        long long n;
        
        int i=num1.length()-1,j=num2.length()-1;
        
        while(i>=0 || j>=0 || rem==1)
        {  

            n = 0;
            if(i>=0)
            {
                n = n + (num1[i]-'0');
                i--;
            }
            if(j>=0)
            {
                n = n +(num2[j]-'0');
                j--;
            }
            
            n = n + rem;
            
            rem =  n/10;
            n = n%10;
            
            temp += char(n+'0');
        }
        
        
        reverse(temp.begin(), temp.end());
        return temp;

    }
};