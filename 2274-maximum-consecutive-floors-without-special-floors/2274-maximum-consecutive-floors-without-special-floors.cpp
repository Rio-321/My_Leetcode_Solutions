class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        special.push_back(bottom-1);
        special.push_back(top+1);
        sort(special.begin(),special.end());
        

        int res = INT_MIN;
        for(int i=1;i<special.size();i++)
        {
            int diff = special[i]-special[i-1]-1;
            res = max(res,diff);
            
        }
        
        return res;
    }
};