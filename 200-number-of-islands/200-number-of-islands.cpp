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
                
                if(i-1>=0 && grid[i-1][j]=='1')
                    adj[s].push_back(n*(i-1)+j);
                if(i+1<m && grid[i+1][j]=='1')
                    adj[s].push_back(n*(i+1)+j);
                if(j-1>=0 && grid[i][j-1]=='1')
                    adj[s].push_back(n*i+j-1);
                if(j+1<n && grid[i][j+1]=='1')
                    adj[s].push_back(n*i+j+1);
                
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