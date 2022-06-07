class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n,0);
        
        int res = 0;
        
        for(int j=0;j<n;j++)
            if(matrix[0][j]=='1')
                height[j] = 1;
            else
                height[j] = 0;
        
        for(int i=0;i<m;i++)
        {
            
            stack<int> st;
            vector<int> left(n);
            // vector<int> right(n);
            
            for(int j=0;j<n && i>0;j++)
            {
               if(matrix[i][j]=='1')
                    height[j] = height[j]+1;
                else
                    height[j] = 0; 
            }
            
            // for(int j=0;j<n;j++)
            //     cout<<height[j]<<" ";
            
                // cout<<"\n";
            
            for(int j=0;j<n;j++)
            {
                
                while(!st.empty() && height[st.top()]>=height[j])
                     st.pop();
                
                if(st.empty())
                    left[j] = j+1;
                else
                    left[j] = j-st.top(); 
                
                
                st.push(j);
                
            }
            
//             for(int j=0;j<n;j++)
//                 cout<<left[j]<<" ";
            
            // cout<<"\n";
            
            while(!st.empty()) st.pop();
            
            // cout<<st.size()<<"\n";
            for(int j=n-1;j>=0;j--)
            {
                while(!st.empty() && height[st.top()]>=height[j])
                    st.pop();
                
                if(st.empty())
                    left[j] = left[j] + n-1-j; 
                else
                    left[j] = left[j] + st.top()-j-1;
                
                st.push(j);
            }
            
            for(int j=0;j<n;j++)
                res = max(res, left[j]*height[j]);
        }
        
        
        return res;
        
    }
};