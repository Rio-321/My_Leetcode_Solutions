class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        
        priority_queue<int> pq;
        
        int count = 1;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(count<=k)
                    pq.push(matrix[i][j]);
                else
                {
                    if(matrix[i][j] < pq.top())
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                        
                }
                
                count++;
            }
        }
        
        return pq.top();
    }
};