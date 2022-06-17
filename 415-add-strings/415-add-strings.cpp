class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string temp;
        int rem = 0;
        long long n;
        
        int i=num1.length()-1,j=num2.length()-1;
        
        while(i>=0 && j>=0)
        {  
            cout<<num1[i]<<" ";
            
            n = (num1[i]-'0') + (num2[j]-'0') + (rem);
            
            cout<<n<<"\n";
            
            rem =  n/10;
            n = n%10;
            
            temp += char(n+'0');
            
            i--;
            j--;
        }
        
        while(i>=0)
        {
            n = (num1[i]-'0') + rem;
            rem = n/10;
            n = n%10;
            temp += char(n+'0');
            
            i--;
        }
        
        while(j>=0)
        {
            n = (num2[j]-'0') + rem;
            rem =  n/10;
            n = n%10;
            
            temp += char(n+'0');
            j--;
        }
        
        if(rem==1)
            temp += '1';
        
        reverse(temp.begin(), temp.end());
        return temp;

    }
};