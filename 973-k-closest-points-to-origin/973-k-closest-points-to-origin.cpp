class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<pair<int,int>> dist;
        vector<vector<int>> res;
        
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            int d = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            
            dist.push_back({d,i});
        }
        
        sort(dist.begin(),dist.end());
        
        for(int i=0;i<k;i++)
        {
            vector<int> temp;
            res.push_back(points[dist[i].second]);
        }
        
        return res;
        
    }
};