class Solution {
public:
    
    bool slope(vector<int> a, vector<int> b, vector<int> c)
    {
        if( ((c[1] - a[1]) * (b[0]-a[0]))  == ((c[0]-a[0]) * (b[1]-a[1]))  )
            return true;
        
        return false;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        if(n <= 2)
            return  n;
        
        int res = 2;
        
        vector<bool> visited(n);
        
        
        for(int i=0; i<n;i++)
        {
            for(int j = i+1; j<n;j++)
            {   
                // if(visited[j])
                //     continue;
                
                int count = 2;
                
                for(int k=0; k<n; k++)
                {
                   if( k!=i && k!= j)
                   {
                       
                       if((points[k][1] - points[i][1])*(points[j][0] - points[i][0]) == (points[j][1] - points[i][1])*(points[k][0]-points[i][0]) )
                       {
                           count++;
                       }
                       
                       // count++;
                       // visited[k] = true;
                   }
                        
                }
                
                res = max(res, count);
                
                if(count == n)
                    return n;
            }
        }
        
        return res;
    }
};