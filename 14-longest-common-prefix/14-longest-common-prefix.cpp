// #include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string temp;
        
        int n = str.size();
        
        int mini = 201;
        
        for(int i=0;i<n;i++)
        {
            int len = str[i].length();
           mini = min(mini, len); 
        }
        
        
         for(int i=0;i<mini;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(j > 0 && str[j][i] != str[j-1][i])
                   return temp;
            }
            
             temp += str[0][i];

        }
        
        return temp;
    }
};