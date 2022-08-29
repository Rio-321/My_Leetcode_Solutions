class Solution {
public:
    int solve(vector<int> &days, vector<int> &costs, int i, int validity, vector<vector<int>> &dp)
    {
         if(i >= days.size())
             return 0;
        
        if(dp[i][validity] != -1)
            return dp[i][validity];
        
         if(days[i] <= validity)
              return dp[i][validity] =  solve(days, costs, i+1, validity, dp);
        
        int oneDay = costs[0] + solve(days, costs, i+1, days[i], dp);
        int sevenDay = costs[1] + solve(days, costs, i+1, days[i]+6, dp);
        int thirtyDay = costs[2] + solve(days, costs, i+1, days[i]+29, dp);
            
         return dp[i][validity] = min({oneDay, sevenDay, thirtyDay});
        
       
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        int max_val = days[days.size()-1] + 30;
        vector<vector<int>> dp(n, vector<int>(max_val, -1));
         return solve(days, costs, 0, 0, dp);
           
    }
};