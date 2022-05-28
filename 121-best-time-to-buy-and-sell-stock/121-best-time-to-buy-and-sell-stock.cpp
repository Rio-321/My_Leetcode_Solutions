class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n==1) return 0;
        
        int profit = 0;
        int minP = prices[0];
        for(int i=1;i<n;i++)
        {
            profit = max(profit, prices[i]-minP);
            minP = min(minP, prices[i]);
        }
        
        return profit;
        
    }
};