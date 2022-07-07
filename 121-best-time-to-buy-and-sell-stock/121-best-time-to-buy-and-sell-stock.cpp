class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
        
        // Optimal Approach - O(n);
        int n = prices.size();
        if(n == 1) return 0;
        int mini = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++)
        {
            profit = max(profit, prices[i]-mini);
            
            mini = min(mini, prices[i]);
        }
        
        return profit;
        
//         // Brute force approach - O(n^2) -- Gives TLE
//         int n = prices.size();
//         if(n == 1) return 0;
//         int profit = 0;
        
//         for(int i=0;i<n-1;i++)
//         {
//             for(int j = i+1; j<n;j++)
//             {
//                 profit = max(profit, prices[j]-prices[i]);
//             }
//         }
        
        
//         return profit;
    }
};