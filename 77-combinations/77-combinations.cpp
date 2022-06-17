class Solution {
public:
    
    vector<vector<int>> res;
    
    void combinations(int index, int n, int k, vector<int> &temp)
    {
        if(temp.size()==k)
        {
            // for(int i=0;i<k;i++)
            //     if(temp[i]==0)
            //         return;
            
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
        int count = 0;
        combinations(1,n,k, temp);
        return res;
    }
};