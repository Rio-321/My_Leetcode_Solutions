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
                    visited[i] = true;
                    res.push_back(s[i]);
                    
                    if(j > 0 && j < numRows-1 && i+2*(numRows-1) - 2*j >= 0 && i+2*(numRows-1) - 2*j < s.length() &&  !visited[i+2*(numRows-1) - 2*j])
                    {
                       // cout<<s[i+2*(numRows-1) - 2*j]<<" "<<i+2*(numRows-1) - 2*j<<"\n";
                        visited[i+2*(numRows-1) - 2*j] = true;
                        res.push_back(s[i+2*(numRows-1) - 2*j]);
                    }
                         
                    
                  
                    
                    i = i+2*(numRows-1);
                }
            
            // cout<<"\n";
        }
        
        
        
        return res;
                 
    }
};