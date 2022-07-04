class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        
        // Optimal Approach
        // https://leetcode.com/problems/partition-labels/discuss/113293/C%2B%2B-6-lines-O(n)-or-O(1)-two-simple-passes
        vector<int> res;
        int n = s.length();
        if(n == 1)
            return {1};
        
        vector<int> max_ind(128,0);

        
        for(int i=0;i<n;i++)
            max_ind[s[i]] = i;
        

        int start = 0;

        int indMax = -1;
        
        for(int i=0;i<n;i++)
        {
            indMax = max(indMax, max_ind[s[i]]);
               
            if(i == indMax)
            {
                res.push_back(i-start+1);
                start = i+1;
            }
        }
        
        return res;
        
    }
};