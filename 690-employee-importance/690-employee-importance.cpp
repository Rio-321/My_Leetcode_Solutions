/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int total_importance(unordered_map<int,vector<int>> adj,int src,unordered_map<int,int> imp)
    {
        int res = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            res += imp[curr];
            
            for(auto x:adj[curr])
                q.push(x);
        }
        
        return res;
            
        
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        int n = employees.size();
        int res = 0;
        
        // vector<int> adj[n+1];
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> imp;
        // vector<int> imp(n+1,0);
        
        cout<<n<<"\n";
        
        int src = id;
        for(int i=0;i<n;i++)
        {   
            int curr = employees[i]->id;
            imp[curr] = employees[i]->importance;
            
            
            for(auto x:employees[i]->subordinates)
                adj[curr].push_back(x);
                
        }
        
        res = total_importance(adj,src,imp);
        
        // cout<<n;
        return res;
        
    }
};