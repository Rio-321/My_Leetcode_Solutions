// https://leetcode.com/problems/snakes-and-ladders/discuss/173378/Diagram-and-BFS
// see comment from shenglia

class Solution {
public:
    
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        queue<int> q;
        q.push(1);
        int ans = 0;
        int goal = n*n;
        
        while(!q.empty())
        {
            ans++;
            int siz = q.size();
            
            for(int i=0;i<siz;i++)
            {
                int curr = q.front();
                q.pop();
                
                for(int i=1;i<=6;i++)
                {
                    int y = curr+i;
                    
                    if(y > goal)
                        continue;
                    
                    int r = (y-1)/n;
                    int c = (y-1)%n;
                    
                    if(r%2 == 1)
                        c = n-1-c;
                    
                     r = n-1-r;
           
                    
                    int &v = board[r][c];
                    
                    if(v == 0) continue;
                    
                    if(v > 0)
                    {
                        y = v;
                    }
                    
                    if(y == goal) return ans;
                    
                    v = 0;
                    q.push(y);
                }
            }
        }
        
        
        return -1;
       

    }
};
