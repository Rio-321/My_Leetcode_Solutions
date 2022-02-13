bool DFS(vector<int> adj[], int s, vector<int> &colors, int p, stack<int> &St, unordered_set<int> &S)
{
    colors[s] = 1;
    St.push(s);
    
    // cout<<s<<" - ";
    for(int x: adj[s])
    {   
        // cout<<x<<" ";
        if(colors[x]==0)
        {
          if(DFS(adj,x,colors,s,St,S))
              return true;
        }
        else if(colors[x]==1 && x!=p)
        {
            // cout<<x<<" ";
            S.insert(x);
            while(St.top()!=x)
            {
                int a = St.top();
                S.insert(a);
                // cout<<a<<" ";
                St.pop();
            }
            
            return true;
        }
        
    }
    
    cout<<"\n";
    
    
    colors[s] = 2; 
    St.pop();
    return false;
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> res;
        
        int n = edges.size();
        
        vector<int> adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
            
            // cout<<a<<" "<<b<<"\n";
        }
        
//         for(int i=1;i<=n;i++)
//         {
//             cout<<i<<" -";
//             for(int x: adj[i])
//                 cout<<x<<" ";
            
//             cout<<"\n";        
//         }
        
        
        // cout<<"\n";
        
        
        vector<int> colors(n+1, 0);
        stack<int> St;
        unordered_set<int> S;
        
        // cout<<St.size()<<"\n";
        
        DFS(adj,1,colors,-1, St,S);
        
        for(int i=n-1;i>=0;i--)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            if(S.find(a)!=S.end() && S.find(b)!=S.end())
            {
                res.push_back(a);
                res.push_back(b);
                
                break;
            }
        }
        
        return res;
    }
};