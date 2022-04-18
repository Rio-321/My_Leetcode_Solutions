class Solution {
public:
    void spiral_matrix(vector<vector<int>> &matrix, int m, int n,int i, int j, vector<int>& vec)
    { 
        int p=i,q=j;
        if(i>m || j>n) return;
        
        // int i=0,j=0;
        
        // cout<<i<<" "<<j<<" "<<m<<" "<<n<<"\n";
        
        for(j;j<=n;j++) vec.push_back(matrix[i][j]);
        j--;
        i++;
        for(i;i<=m;i++) vec.push_back(matrix[i][j]);
        i = m;
        j = n-1;
        for(j;i>p && j>=q;j--) vec.push_back(matrix[i][j]);
        i = m-1;
        j = q;
        for(i;i>p && j<n;i--) vec.push_back(matrix[i][j]);
    
    
        
        // cout<<i<<" "<<j<<"\n";
        
        spiral_matrix(matrix,m-1,n-1,p+1,q+1,vec);
        
        return;
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> vec;
        int m = matrix.size();
        int n = matrix[0].size();
        spiral_matrix(matrix,m-1,n-1,0,0,vec);
        
        // for(auto x:vec)
        //     cout<<x<<" ";
        
        return vec;
    }
};