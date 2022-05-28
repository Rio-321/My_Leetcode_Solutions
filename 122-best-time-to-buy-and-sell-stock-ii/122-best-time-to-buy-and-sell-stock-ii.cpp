class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;
        int i=0;
        while(i<(prices.size()-1))
        {
            while(i<n-1 && prices[i] >= prices[i+1])
            {
                i++;
            }
            while(i<n-1 && prices[i] < prices[i+1])
            {
                profit = profit + (prices[i+1]-prices[i]);
                i++;
            }
            
        }
        
        return profit;
    }
};