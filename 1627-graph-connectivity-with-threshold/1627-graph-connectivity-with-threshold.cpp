class Solution {
public:
    
    // https://leetcode.com/problems/graph-connectivity-with-threshold/discuss/2570489/C%2B%2B-DSU-%2B-Sieve-of-Eratosthenes
    
int parent(int a, vector<int> &dsu)
{
    if(dsu[a] == a)
        return a;
    
    return dsu[a] = parent(dsu[a], dsu);
}
    
void Union(int a, int b, vector<int> &dsu)
{
    int parA = parent(a, dsu);
    int parB = parent(b, dsu);
    
    if(parA == parB) return;
    int maxPar = max(parA, parB);
    
    dsu[parA] = maxPar;
    dsu[parB] = maxPar;
}
    
vector<bool> areConnected(int n, int x, vector<vector<int>>& queries) {
        
    vector<int> dsu(n+1);
    iota(dsu.begin(), dsu.end(), 0);
    
    vector<bool> marked(n+1);
    for(int i = x+1;i<=n;i++)
    {
        if(marked[i] == false)
        {
            int j = i;
            while(j <= n)
            {
                marked[j] = true;
                Union(i, j, dsu);
                j = j+i;
            }
        }
    }
    
    vector<bool> ans;
    
    for(int i=0;i<queries.size();i++)
    {
        int u = queries[i][0];
        int v = queries[i][1];
        
        if(parent(u, dsu) == parent(v, dsu))
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    
    return ans;
  
    }
};