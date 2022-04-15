class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ANS;
        
        ANS.push_back({1});
        
        numRows--;
        
        while(numRows--)
        {
            vector<int> curr;
            curr.push_back(1);
            for(int i=0;i<ANS[ANS.size()-1].size()-1;i++)
            {
                curr.push_back(ANS[ANS.size()-1][i] + ANS[ANS.size()-1][i+1]);
            }
            curr.push_back(1);
            
            ANS.push_back(curr);
            
        }
        
        
        return ANS;
        
        
        
        
    }
};