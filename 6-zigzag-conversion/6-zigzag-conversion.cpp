class Solution {
public:
    
    // My Solution
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        vector<bool> visited(s.length());
        
        string res = "";
        for(int j=0;j<numRows;j++)
        {
                int i = j;
                // cout<<j<<"\n";
                while(i < s.length())
                {
                      // cout<<s[i]<<" "<<i<<"\n";
                    if(!visited[i])
                    {
                         visited[i] = true;
                         res.push_back(s[i]);
                    }
                   
                    
                    // i + 2*(numRows - 1 - j)
                    
                    if( (i + 2*(numRows - 1 - j)) < s.length() &&  !visited[i + 2*(numRows - 1 - j)])
                    {
                       // cout<<s[i+2*(numRows-1) - 2*j]<<" "<<i+2*(numRows-1) - 2*j<<"\n";
                        visited[i + 2*(numRows - 1 - j)] = true;
                        res.push_back(s[i + 2*(numRows - 1 - j)]);
                    }
                         
                    
                  
                    
                    i = i+2*(numRows-1);
                }
            
            // cout<<"\n";
        }
        
        
        
        return res;
                 
    }
};