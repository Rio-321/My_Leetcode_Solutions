class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<int> indegree(n);
        vector<int> adj[n];
        
        // for(int x : indegree)
        //     cout<<x<<" ";
        
        int edges = prerequisites.size();
        
        for(int i=0;i<edges;i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            
            indegree[a]++;
            adj[b].push_back(a);
        }
        
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        
        int count = 0;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(int x: adj[curr])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
            
            count++;
        }
        
        if(count==n)
            return true;
        else 
            return false;
        
    }
};