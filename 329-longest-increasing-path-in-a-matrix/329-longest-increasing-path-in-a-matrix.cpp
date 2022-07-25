class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    
    int DFS(int i, int j, vector<vector<int>> &matrix)
    {
        if(dp[i][j] != 0) return dp[i][j];
        
        int move[5] = {-1,0,1,0,-1};
        
        int res = 0;
        for(int k=0;k<4;k++)
        {
            int next_i = i + move[k]; 
            int next_j = j + move[k+1];
            
            if(next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && matrix[next_i][next_j] > matrix[i][j])
            res = max(res, DFS(next_i, next_j,matrix));
            
        }
        
        dp[i][j] = res + 1;
        
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        m = matrix.size();
        n = matrix[0].size();
        
        dp = vector<vector<int>> (m, vector<int>(n,0));
        
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                ans = max(ans, DFS(i,j,matrix));
                
        }
        
        return ans;
         
        
    }
};