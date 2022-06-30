// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     void DFS(int src, vector<vector<int>> &adj, vector<bool> &visited, int V)
     {
         visited[src] = true;
         
         for(int j=0;j<V;j++)
         {
             int x = adj[src][j];
             if(x==1 && !visited[j])
             {
                 DFS(j,adj,visited,V);
             }
         }
     }
     
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count = 0;
        vector<bool> visited(V);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(i,adj,visited, V);
                count++;
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends