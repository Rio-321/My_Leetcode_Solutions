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

                while(i < s.length())
                {

                    if(!visited[i])
                    {
                         visited[i] = true;
                         res.push_back(s[i]);
                    }
                   
                    int next = i + 2*(numRows - 1 - j);
                    
                    if( next < s.length() &&  !visited[next])
                    {

                        visited[next] = true;
                        res.push_back(s[next]);
                    }
                          
                    i = i+2*(numRows-1);
                }
            
        }
        
        
        return res;
                 
    }
};