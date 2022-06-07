class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> degree(n+1,0);
        
        for(int i=0;i<trust.size();i++)
        {
            degree[trust[i][0]]--;
            degree[trust[i][1]]++;
        }
        
        
        for(int i=1;i<=n;i++)
            if(degree[i]==n-1)
                return i;
        
        return -1;
        
    }
};