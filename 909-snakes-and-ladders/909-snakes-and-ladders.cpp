class Solution {
public:
    
    int No_Of_Moves(int curr, int dest, unordered_map<int,int> path, int n)
    {  
        queue<int> q;
        q.push(1);
        q.push(0);
        int ans = 0;
        
        vector<bool> visited(n*n+1);
        visited[1] = true;
        
        
        while(q.size()>1)
        {
            int curr = q.front();
            q.pop();
            
            // cout<<curr<<" ";
            if(curr==0)
            {
                q.push(0);
                ans++;
                // cout<<"\n";
                continue;
            }
            
            if(curr==dest)
                return ans;

             for(int i=1;i<=6 && curr+i<=n*n;i++)
            {
                int next = curr+i;
                if(path.find(next)!=path.end())
                {
                    if(path[next]<next && !visited[path[next]])
                    {
                           visited[path[next]] = true;
                           q.push(path[next]);
                    }
                    else if(path[next]>next && !visited[path[next]])
                    {
                            visited[path[next]] = true;
                            q.push(path[next]);
                    }

                }
                 else
                {
                    if(!visited[next])
                     {
                         visited[next] = true;                       
                         q.push(next);
                     }
                }

            }
                    
                
        }
        
        return -1;
           
    }
        

    
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        unordered_map<int,int> path;
        
        int num  = 1;   
        int flag = 0;
        
        for(int i=n-1;i>=0;i--)
        {    
            flag = flag ^ 1;
            if(flag==1)
            {
                for(int j=0;j<n;j++)
                { 
                    if(board[i][j]!=-1)
                        path[num] = board[i][j];
                    num++;
                }
                    
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(board[i][j]!=-1)
                        path[num] = board[i][j];
                        num++;
                }
                    
            }
        }

        
        return No_Of_Moves(1,n*n,path,n);

    }
};