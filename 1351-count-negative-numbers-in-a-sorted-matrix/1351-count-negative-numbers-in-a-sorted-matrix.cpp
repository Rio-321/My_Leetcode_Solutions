class Solution {
public:
    
    int f(vector<vector<int>> &grid, int i, int low, int high)
    {       
            int n = high+1;
            int ans = n;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(grid[i][mid]<0 && (mid==0 || grid[i][mid-1]>=0))
                    return n-mid;
                
                if(grid[i][mid]>=0)
                    low = mid+1;
                else
                {
                    ans = mid;
                    high = mid-1;
                }
            }
            
            return n-ans;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++)
        {
            res = res + f(grid,i,0,n-1);  
        }
        
        return res;
    }
};