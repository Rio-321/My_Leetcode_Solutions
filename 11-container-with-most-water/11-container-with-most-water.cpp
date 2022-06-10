class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        
        int res = 0;
        int l=0,r=n-1;
        while(l<r)
        {
            res = max(res,(r-l)*min(height[l],height[r]));
            
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        
        return res;
    }
};