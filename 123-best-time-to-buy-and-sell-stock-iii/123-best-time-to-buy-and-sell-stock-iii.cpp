class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        
        int n = prices.size();
        if(n == 1) return 0;
        int profit = 0;
       
        
        vector<int> pre_profit(n, 0);
        
        int mini = prices[0];
        for(int i=1;i<n;i++)
        {
            profit = max(profit, prices[i]-mini);
            pre_profit[i] = profit;
            
            mini = min(mini, prices[i]);
        }
        
        int maxi = prices[n-1];
        profit = 0;
        
        int res = (pre_profit[n-2], pre_profit[n-1]);
        
        for(int i=n-2;i>0;i--)
        {
            profit = max(profit, maxi-prices[i]);
            
            res = max(res, pre_profit[i-1] + profit);
            
            maxi = max(maxi, prices[i]);
        }

        
        
        return res;
    }
};