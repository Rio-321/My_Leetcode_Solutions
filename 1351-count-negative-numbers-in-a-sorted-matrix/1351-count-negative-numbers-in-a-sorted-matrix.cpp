class Solution {
public:
    
//     int f(vector<vector<int>> &grid, int i, int low, int high)
//     {       
//             int n = high+1;
//             int ans = n;
//             while(low<=high)
//             {
//                 int mid = (low+high)/2;
//                 if(grid[i][mid]<0 && (mid==0 || grid[i][mid-1]>=0))
//                     return n-mid;
                
//                 if(grid[i][mid]>=0)
//                     low = mid+1;
//                 else
//                 {
//                     ans = mid;
//                     high = mid-1;
//                 }
//             }
            
//             return n-ans;
//     }
    
    int countNegatives(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
//         int res = 0;
//         for(int i=0;i<m;i++)
//         {
//             res = res + f(grid,i,0,n-1);  
//         }
        
         
          int i = m-1, j = 0;
          int ans = 0;
        
        while(i>=0)
        {  
            
            while(j<n && mat[i][j]>=0)            
                    j++;
            
            ans += (n-j);
            
            i--;
            // j++;
            
            
        }

        return ans;
        
        
        
    }
};