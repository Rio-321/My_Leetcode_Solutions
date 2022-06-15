class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        
        
        vector<double> Prob(n,0.00);
        Prob[start] = 1.00;

        
        vector<bool> visited(n);
        
        for(int count=0;count<n;count++)
        {
            int u = -1;
            double max_prob = 0;
            for(int i=0;i<n;i++)
            {
                if(!visited[i] && Prob[i]>max_prob) // Prob[i]>=max_prob
                {
                    max_prob = Prob[i];
                    u = i;
                }
            }
            
            if(u==-1)
                return max_prob;
            
            visited[u] = true;
            
            if(u==end)
                return Prob[u];
            
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i].first;
                double p = adj[u][i].second;
                
                if(!visited[v])
                {
                    Prob[v] = max( Prob[v], Prob[u]*p );                
                }
                    
            }
            

        }
        
        
        return Prob[end];
        
    }
};