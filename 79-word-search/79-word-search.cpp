class Solution {
public:
    
    bool is_safe(int i, int j, int m, int n,vector<bool> &visited)
    {
        if(i<m && i>=0 && j>=0 && j<n && !visited[n*i+j])
            return true;
        else
            return false;
    }
    
    
    bool is_exist(vector<vector<char>>& board,string word,int indx,int i, int j,int m,int n, vector<bool> &visited)
    {
        
        if(is_safe(i,j,m,n,visited)==true)
        {
           if(board[i][j]==word[indx])
           {   
               visited[n*i+j] = true;
               
               if(indx==word.length()-1) return true;
               
               vector<int> dir={-1,0,1,0,-1};
               for(int k=0;k<4;k++)
               {
                    int r = i + dir[k];
                    int c = j + dir[k+1];
                   
                    if(is_exist(board,word,indx+1,r,c,m,n,visited)==true)
                        return true;  
               }
               
               visited[n*i+j] = false;
               return false;  
              
           }
            else
                return false;
        }
        else
            return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<bool> visited(m*n);
      
        for(int i=0;i<m;i++)
        {
           for(int j=0;j<n;j++)
            {   
               // cout<<n*i+j<<" ";
                if(is_exist(board,word,0,i,j,m,n,visited)==true)
                    return true;
            } 
        }     
        return false;
        
    }
};










  
//         vector<int> vec;
        
//         // for(int i=0;i<m;i++)
//         //     for(int j=0;j<n;j++)
//         //         if(board[i][j]==word[0])
//         //             vec.push_back(n*i+j);