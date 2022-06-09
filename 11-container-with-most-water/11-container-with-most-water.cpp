class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        
        int res = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(height[j]>=height[i])
                {
                    res = max(res, height[i]*(i-j));
                    break;
                }
            }
            
            // cout<<res<<" ";
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(height[j]>=height[i])
                {
                    res = max(res, height[i]*(j-i));
                    break;
                }
            }
        }
        
        return res;
    }
};