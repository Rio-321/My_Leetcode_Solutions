class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
    
        int res = 0;
        queue<int> q;
        int fresh = 0;
        
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push(n*i+j); 
                
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        
        // cout<<fresh<<"\n";
        
        while(!q.empty())
        {
            int count = q.size();
            
            // cout<<count<<"\n";
            
            if(count==0)
                break;
            
            while(count--)
            {
                int curr = q.front();
                q.pop();
                
                int move[5] = {-1,0,1,0,-1};
                for(int k=0;k<4;k++)
                {
                    int i = curr/n + move[k];
                    int j = curr%n + move[k+1];
                    
                    if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1)
                    {
                        q.push(n*i+j);
                        grid[i][j] = 2;
                        fresh--;
                    }
                    
                }
            }
            
            res++;
        }
        
        // cout<<fresh<<"\n";
        
        
        
        
        
        if(fresh==0)
            res = max(0,--res);
        
        if(fresh>0)
            res =  -1;
        
        
        return res;
        
    }
};