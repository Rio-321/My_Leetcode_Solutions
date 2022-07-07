class Solution {
public:
    
    // Optimal solution
    int solve(int ind, int trans, vector<int> &prices, int &k, vector<vector<int>> &dp)
    {
        
        if(ind == prices.size() || trans == 2*k)
            return 0;
        
        if(dp[ind][trans] != -1)
            return dp[ind][trans];
        
        if(trans%2 ==0 )  // buy
        {
           return dp[ind][trans] = max( (-prices[ind] + solve(ind+1, trans+1, prices, k, dp)), solve(ind+1, trans, prices, k, dp)) ;
        }
        else //  sell
        {
             return dp[ind][trans] = max( (prices[ind] + solve(ind+1, trans+1, prices, k, dp)), solve(ind+1, trans, prices, k, dp)) ;
        }
        
            
    }
    
    
    int maxProfit(int k, vector<int>& prices) 
    {
           
        int trans = 0;
        int profit = 0;
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        
        profit = solve(0,trans, prices, k, dp);
        return profit;
        
       
        
    }
};