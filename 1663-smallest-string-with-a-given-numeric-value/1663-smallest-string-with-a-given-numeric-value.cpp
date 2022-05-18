class Solution {
public:
    string getSmallestString(int n, int k) {
        
        int x = 0;
        int p = -1;
        for(;x<=n;x++)
        {
            p = k - 26*x + 1 - n + x;
            if(p>=0 && p<=26)
                break;
        }
        
        string res = "";
        int num = n-1-x;
        while(num--)
            res.push_back('a');
        
        char ch = char(p+96);
        res.push_back(ch);
        
            while(x--)
            res.push_back('z');
        
        
        return res;
    }
};