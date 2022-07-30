// good solution - // https://leetcode.com/problems/cherry-pickup/discuss/1481719/c%2B%2B-fully-explained-recursion-%2B-memoisation-approach-.


class Solution {
    
public:
    
    vector<vector<vector<int>>> dp;
    
    int helper(int r1, int c1, int r2, vector<vector<int>>&grid, int n)
    {
        int c2 = r1 + c1 - r2;
        
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];
        
        
        int res = 0;
        
        
        int a = helper(r1+1,c1,r2+1,grid,n);
        int b = helper(r1+1,c1,r2,grid,n);
        int c = helper(r1,c1+1,r2+1,grid,n);
        int d = helper(r1,c1+1,r2,grid,n);
        
        int maxi = max(max(a,b), max(c,d));
        
        if(r1==r2 && c1==c2)
        {
            res = grid[r1][c1];
        }
        else
        {
            res = grid[r1][c1] + grid[r2][c2];
        }
        
        res = res + maxi;
         
        dp[r1][c1][r2]  = res;
        
        return  res;
    }
    
    

    
int cherryPickup(vector<vector<int>> &grid) 
    {
       
        int n = grid.size();
        
        dp = vector<vector<vector<int>>> (n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        
            
        int ans =  max(0, helper(0,0,0,grid,n));
    
         return ans;
        
    }
};