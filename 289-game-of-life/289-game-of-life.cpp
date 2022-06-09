class Solution {
public:
    
    int m=0,n=0;
    
    void convert(vector<vector<int>> &board, int i, int j,vector<vector<int>> &ans)
    {
        
         int cnt = 0;
            int i_move[8] = {-1,-1,-1,0,0,1,1,1};
            int j_move[8] = {-1,0,1,-1,1,-1,0,1};
            
            for(int k=0;k<8;k++)
            {
                int x = i+i_move[k];
                int y = j+j_move[k];
                if(x>=0 && x<m && y>=0 && y<n && board[x][y]==1)
                    cnt++;
            }
        
        cout<<cnt;
        
        if(board[i][j]==1)
        {
            if(cnt<2 || cnt>3) 
                ans[i][j] = 0; 
            else
                ans[i][j] = 1;
        }
        else
        {
            if(cnt==3) ans[i][j] = 1;
        }
        
        
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        m = board.size();
        n = board[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                convert(board,i,j,ans);
                cout<<" ";
            }
            cout<<"\n";
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j] = ans[i][j];
            }
        }
        
        
        
    }
};