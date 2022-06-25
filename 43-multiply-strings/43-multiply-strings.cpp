class Solution {
public:
    
    string addStrings(string str1, string str2)
{
    string res = "";

    int rem = 0;
    int curr = 0;
    int len1 = str1.length();
    int len2 = str2.length();

    int max_len = max(len1, len2);

    str1 = string( max_len - len1, '0') + str1;
    str2 = string( max_len - len2, '0') + str2;

    // cout<<str1<<br;
    // cout<<str2<<br;


    for(int i=max_len-1;i>=0;i--)
    {

        curr = (str1[i] - '0') + (str2[i]-'0') + rem;
        rem = curr/10;
        curr = curr % 10;
        res = char(curr + '0') + res;
    }

    // cout<<rem<<br;

    if(rem)
        res = char(rem + '0') + res;

    // cout<<res<<br;

    return res;
}
    
    string multiply(string str1, string str2) {
        
    int len1 = str1.length();
    int len2 = str2.length();

    // int max_len = max(len1, len2);

    // str1 = string( max_len- len1, '0') + str1;
    // str2 = string( max_len- len2, '0') + str2;

    // cout<<str1<<br;
    // cout<<str2<<br;
    
    string prev = "";
    for(int j=len2-1;j>=0;j--)
    {
         int rem = 0;
         int curr = 0;
         string res = "";

         res = res + string(len2-1-j, '0');

         for(int i=len1-1;i>=0;i--)
        {
            curr = ((str1[i] - '0') * (str2[j]-'0')) + rem;
            // cout<<curr<<br;
            rem = curr/10;
            curr = curr % 10;
            res = char(curr + '0') + res;
        }

        if(rem)
        res = char(rem + '0') + res;

        // cout<<res<<br;

        prev = addStrings(prev, res);
    }
   

    // cout<<rem<<br;

    

    // cout<<prev<<br;
        
        int ind = -1;
 for(int i=0;i<prev.length()-1;i++)
   {
      if(prev[i] != '0')
          break;
     else
         ind = i;
      
   }

   prev.erase(prev.begin(), prev.begin() + ind+1);

   // cout<<str<<br;
        return prev;
        
        
    }
};