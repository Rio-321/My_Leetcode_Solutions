class Solution {
public:
    vector<vector<int>> RES;
    vector<int> vec;
    
    void Print_Path(vector<vector<int>> &graph, int src, int dest)
    {
        vec.push_back(src);
        if(src==dest) 
        {
            RES.push_back(vec);
            vec.pop_back();
            return ;
        }
        
        for(auto x: graph[src])
        {
            Print_Path(graph,x,dest);
        }
        
        vec.pop_back();
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        Print_Path(graph,0,graph.size()-1);
        
        return RES;
        
    }
};