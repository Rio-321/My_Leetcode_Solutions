class Solution {
public:
    
    vector<vector<int>> res;
    
    void combinations(int index, int n, int k, vector<int> &temp)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return;
        }
        
        
        for(int i=index;i<=n;i++)
        {
            temp.push_back(i);
            combinations(i+1,n,k, temp);
            temp.pop_back(); 
                
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp;
        combinations(1,n,k, temp);
        return res;
    }
};