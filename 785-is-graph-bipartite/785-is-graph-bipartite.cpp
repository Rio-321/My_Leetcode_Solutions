class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> visited(n,0);
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                q.push(i);
                visited[i] = 1;

                while(!q.empty())
                {
                    int curr = q.front();
                    q.pop();

                    for(auto x:graph[curr])
                    {
                        if(visited[x]==0)
                        {
                            visited[x] = (visited[curr] == 1 ? 2 : 1);
                            q.push(x);
                        }
                        else
                        {
                            if(visited[x]==visited[curr])
                                return false;

                        }
                    }
                } 
            }
            
        }
       
        
        return true;
    }
};