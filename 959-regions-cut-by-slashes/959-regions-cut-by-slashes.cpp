class Solution {
public:
    
    int count = 1;
    vector<int> parent;
    vector<int> rank;
    
    int findParent(int node)
    {
        if(parent[node] == node)
            return node;
        
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    
    void unionize(int a, int b)
    {
        int parentA = findParent(a);
        int parentB = findParent(b);
        
        if(parentA != parentB)
        {
            if(rank[parentA] > rank[parentB])
                 parent[parentB] = parentA;
            else if(rank[parentA] < rank[parentB])
                parent[parentA] = parentB;
            else
                parent[parentB] = parentA;
                rank[parentA]++;
        }
        else
            count++;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        
        int  n = grid.size();
        
        // cout<<n<<"\n";
        
        // int count = 1;
        
        int p = n+1;
        
        parent.resize(p*p);
        rank.resize(p*p, 1);
        
        for(int i=0;i<parent.size();i++)
             parent[i] = i;
        
        
        // vector<bool> visited((n+1)*(n+1), false);
        
        for(int j=0;j<=n;j++)
        {
            parent[j] = 0;
            parent[(n+1)*(n)+j] = 0;
        }
        
        for(int i=0;i<=n;i++)
        {
            parent[(n+1)*i] = 0;
            parent[(n+1)*i+n] = 0;
        }
        
        
        
        for(int i=0; i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c = grid[i][j];
                
                if(c == '/')
                {
                    
                    unionize(((n+1)*i)+j+1, ((n+1)*(i+1))+j);
                    
//                     if(visited[((n+1)*i)+j+1] && visited[((n+1)*(i+1))+j])
//                         count++;
                    
//                     if(!visited[((n+1)*i)+j+1] && !visited[((n+1)*(i+1))+j])
//                     {
                        
//                     }
//                     else
//                     {
//                        visited[((n+1)*i)+j+1] = true;
//                         visited[((n+1)*(i+1))+j] = true; 
//                     }
                    
                    
                    
                }
                else if(c == '\\')
                {
                    
                    unionize(((n+1)*i)+j, ((n+1)*(i+1))+j+1);
//                     if(visited[((n+1)*i)+j] && visited[((n+1)*(i+1))+j+1])
//                         count++;
                    
//                     if(!visited[((n+1)*i)+j] && !visited[((n+1)*(i+1))+j+1])
//                     {
                        
//                     }
//                     else
//                     {
//                          visited[((n+1)*i)+j] = true;
//                          visited[((n+1)*(i+1))+j+1] = true;
//                     }
                    
                   
                }
                
                // cout<<i<<" "<<j<<" - "<<count<<"\n";
                
            }
        }
        
        
        return count;
        
        
    }
};