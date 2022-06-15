class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            u--;
            v--;
            adj[u].push_back({v,w});
        }
        
        k--;
        
        vector<int> Dist(n,INT_MAX);
        Dist[k] = 0;
                         
        vector<bool> visited(n);
                         
        for(int count=0;count<n-1;count++)
         {
             int u=-1;
             int min_dist = INT_MAX;

             for(int i=0;i<n;i++)
             {
                 if(!visited[i] && Dist[i]<min_dist)
                 {
                     min_dist = Dist[i];
                     u = i;
                 }
             }
            
            // cout<<u<<"\n";
            if(u==-1)
            return -1;

             visited[u] = true;

             for(int i=0;i<adj[u].size();i++)
             {
                 int v1 = adj[u][i].first;
                 int w1 = adj[u][i].second;
                 
                 if(!visited[v1])
                 {
                     Dist[v1] = min(Dist[v1], Dist[u]+w1);
                 }
             }


         }
                   
            int res = INT_MIN;
            for(int i=0;i<n;i++)
             {
                 res = max(res,Dist[i]);
             }

             if(res==INT_MAX)
                return -1;
             else
                return res;
    }
};