class Solution {
public:
    
    int longestPalindrome(string s) {
    
        // vector<int> freq(26,0);
        unordered_map<int,int> freq;
        for(auto x:s)
            freq[x-'a']++;
        
        int odd = 0,even=0;
        int res = 0;
        
        for(auto x:freq)
        {
            if(x.second%2==0)
            {
                res += x.second;
            }
            else
            {
                odd++;
                res += (x.second)-1;
            }
                  
        }
        
        if(odd>0)
            res++;
        
        return res;
        
    }
};