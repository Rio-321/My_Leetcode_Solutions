class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        int fir = max(cost1,cost2);
        int sec = min(cost1,cost2);
        
        int lim = total/fir;
        long long res = 0;
        
        for(int i=0;i<=lim;i++)
        {
            res = res + ((total - (i*fir))/sec + 1);
        }
        
        return res;
    }
};