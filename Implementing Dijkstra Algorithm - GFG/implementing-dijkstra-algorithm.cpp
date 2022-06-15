// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> Dist(V,INT_MAX);
        vector<bool> visited(V);
        
        Dist[S] = 0;
        // visited[S] = true;
        
        for(int count = 0;count<V-1;count++)
        {
            int u = -1;
            int minDist = INT_MAX;
            for(int i=0;i<V;i++)
            {
                if(Dist[i]<minDist && !visited[i])
                {
                    minDist = Dist[i];
                    u = i;
                }
            }
            
            // cout<<u<<" ";
            
            visited[u] = true;
            
            for(int i=0;i<adj[u].size();i++)
            { 
                if(!visited[adj[u][i][0]])
                  Dist[adj[u][i][0]] = min(Dist[adj[u][i][0]], Dist[u] + adj[u][i][1]);
            }
        }
        
        // cout<<"\n";
        
        return Dist;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends