class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
;        int T = 0,B=m-1,L=0,R=n-1;
        int dir = 0;
        
        vector<int> vec;
        
        while(T<=B && L<=R)
        {
            if(dir==0)
            {
                for(int j=L;j<=R;j++)
                    vec.push_back(matrix[T][j]);
                
                    T++;
            }
            
            if(dir==1)
            {
                for(int i=T;i<=B;i++)
                    vec.push_back(matrix[i][R]);
                
                    R--;
            }
            
            if(dir==2)
            {
                for(int j=R;j>=L;j--)
                    vec.push_back(matrix[B][j]);
                
                    B--;
            }
            
            if(dir==3)
            {
                for(int i=B;i>=T;i--)
                    vec.push_back(matrix[i][L]);
                
                    L++;
            }
            
            dir = (dir+1)%4;
            
           
        }
        
        return vec;
        
       
    }
};