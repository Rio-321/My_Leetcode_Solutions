class Solution {
public:
    
    bool slope(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        if( (c[1] - b[1]) * (b[0]-a[0])  ==  (c[0]-b[0]) * (b[1]-a[1]) )
            return true;
        
        return false;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        if(n <= 2)
            return  n;
        
        int res = 0;
        
        
        for(int i=0; i<n-2;i++)
        {
            for(int j = i+1; j<n-1;j++)
            {   
                
                int count = 2;
                
                for(int k=j+1; k<n; k++)
                {
                   if( slope(points[i], points[j], points[k]) )
                   {
                       count++;
                   }
                        
                }
                
                res = max(res, count);
            }
        }
        
        return res;
    }
};