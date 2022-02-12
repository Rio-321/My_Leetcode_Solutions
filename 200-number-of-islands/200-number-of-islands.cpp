void BFS(vector<int> adj[], int s, vector<bool> &visited)
{
    visited[s] = true;
    queue<int> q;
    q.push(s);
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(int x:adj[curr])
        {
            if(!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        // cout<<m<<" and "<<n<<"\n";
        
        vector<int> adj[m*n];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]=='0')
                    continue;
                
                
                int s = n*i+j;
                // cout<<s<<" ";
                
                vector<int> X_Move = {-1,0,1,0};
                vector<int> Y_Move = {0,-1,0,1};
                
                for(int k=0;k<4;k++)
                {  
                    int x = i + X_Move[k];
                    int y = j + Y_Move[k];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1')
                        adj[s].push_back(n*x+y);
                }
                
                // if(i-1>=0 && grid[i-1][j]=='1')
                //     adj[s].push_back(n*(i-1)+j);
                // if(i+1<m && grid[i+1][j]=='1')
                //     adj[s].push_back(n*(i+1)+j);
                // if(j-1>=0 && grid[i][j-1]=='1')
                //     adj[s].push_back(n*i+j-1);
                // if(j+1<n && grid[i][j+1]=='1')
                //     adj[s].push_back(n*i+j+1);
                
            }
            // cout<<"\n";
        }
        
        vector<bool> visited(m*n);
        
        for(int i=0;i<m*n;i++)
        {
            if(!visited[i] && grid[i/n][i%n]=='1')
            {
                count++;
                // cout<<i<<"\n";
                BFS(adj,i,visited);
            }
                
        }
        
        // cout<<adj[12].size()<<"\n";
        return count;
        
    }
};