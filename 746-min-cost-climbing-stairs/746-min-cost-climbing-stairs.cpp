class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int first = 0,second=0;
        int res = 0;
        
        for(int i=2;i<=n;i++)
        {
            res =  min(first+cost[i-2], second+cost[i-1]);
            first = second;
            second = res;
        }
            
        
        return res ; 
        
        
    }
};