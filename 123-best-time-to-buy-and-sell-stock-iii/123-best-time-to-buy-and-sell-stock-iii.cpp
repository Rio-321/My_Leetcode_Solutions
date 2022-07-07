class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        
        int n = prices.size();
        int profit = 0;
       
        
        vector<int> pre_profit(n, 0);
        vector<int> post_profit(n, 0);
        
        int mini = prices[0];
        for(int i=1;i<n;i++)
        {
            profit = max(profit, prices[i]-mini);
            pre_profit[i] = profit;
            
            mini = min(mini, prices[i]);
        }
        
        int maxi = prices[n-1];
        profit = 0;
        
        for(int i=n-2;i>=0;i--)
        {
            profit = max(profit, maxi-prices[i]);
            post_profit[i] = profit;
            
            maxi = max(maxi, prices[i]);
        }
        
        profit = 0;
        
        for(int i=0;i<n-1;i++)
        {
           profit = max(profit, pre_profit[i]+post_profit[i+1]); 
        }
        profit = max({profit, pre_profit[n-1], post_profit[0]});
        
        
//         for(auto x:post_profit)
//             cout<<x<<" ";
        
//         cout<<"\n";
        
        
        return profit;
    }
};