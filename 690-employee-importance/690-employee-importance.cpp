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
    
    int total_importance(unordered_map<int,Employee*> adj,int src)
    {
        int res = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            res += adj[curr]->importance;
            
            for(auto x:adj[curr]->subordinates)
                q.push(x);
        }
        
        return res;
            
        
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        int n = employees.size();
        int res = 0;
        

        unordered_map<int, Employee*> adj;
        unordered_map<int,int> imp;
        
        

        
        cout<<n<<"\n";
        
        int src = id;
        for(int i=0;i<n;i++)
        {   
            int curr = employees[i]->id;
            adj[curr] = employees[i];
            
            
//             for(auto x:employees[i]->subordinates)
//                 adj[curr].push_back(x);
                
        }
        
        res = total_importance(adj,src);
        
        
        
        // cout<<n;
        return res;
        
    }
};