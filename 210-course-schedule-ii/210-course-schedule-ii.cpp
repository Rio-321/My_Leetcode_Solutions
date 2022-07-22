class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        int n = prerequisites.size();
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses);
    
        
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            res.push_back(curr);
            
            for(int x:adj[curr])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
            
            count++;
        }
        
        if(count==numCourses)
            return res;
        
        // res.clear();
        
        return {};
        
    }
};