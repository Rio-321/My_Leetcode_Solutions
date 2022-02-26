class Solution {
public:
    bool canWinNim(int n) {
        
        bool res = true;
        
        if(n%4==0)
            res = false;
        
        return res;
        
    }
};