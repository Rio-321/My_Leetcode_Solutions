class Solution {
public:
    bool judgeCircle(string moves) {
        int ver = 0;
        int hor = 0;
        
        int n = moves.size();
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='U')
                ver++;
            if(moves[i]=='D')
                ver--;
            if(moves[i]=='R')
                hor++;
            if(moves[i]=='L')
                hor--;
        }  
        
        
        if(ver==0 && hor==0)
            return true;
        else
            return false;
    }
};