class Solution {
public:
    
    // Approach 2: Optimised DP Solution
    
    int trap(vector<int>& height) {
        
            int n = height.size();
            int l = 0, r = n-1;
            int maxleft = 0, maxright = 0;
        long long ans = 0;
        
        while(l <= r)
        {
            if(height[l] <= height[r])
            {
                if(height[l] >= maxleft)
                    maxleft = height[l];
                else
                    ans += maxleft-height[l];
                
                l++;
            }
            else
            {
                if(height[r] >= maxright)
                    maxright = height[r];
                else
                    ans += maxright-height[r];
                
                r--;
            }
        }
        
//         int n = height.size();
//         if(n<=2) return 0;
        
//         int res = 0;
        
//         vector<int> left_max(n), right_max(n);
        
//         for(int i=0;i<n;i++)
//         {
//             left_max[i] = (i == 0) ? height[i] : max(left_max[i-1], height[i]);
//         }
        
//         for(int i=n-1;i>=0;i--)
//         {
//             right_max[i] = (i == n-1) ? height[i] : max(right_max[i+1], height[i]);
//         }
       
//         for(int i=0;i<n;i++)
//         {
//             // int left_max = 0, right_max = 0;
// //             for(int j=0;j<=i;j++)
// //             {
// //                 left_max = max(left_max, height[j]);
// //             }
            
// //             for(int k=i;k<n;k++)
// //             {
// //                 right_max = max(right_max, height[k]);
// //             }
            
//             int diff = min(left_max[i], right_max[i]) - height[i];
            
//             // if(i == 8)
//             // {
//             //     cout<<left_max<<" ";
//             //    cout<<diff<<" "; 
//             // }
             
            
//             if(diff > 0)
//                 res = res + diff;
            
            
//         }
        
//         return res;
        
        return ans;
    }
};