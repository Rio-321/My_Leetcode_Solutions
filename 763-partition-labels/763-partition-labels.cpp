class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> res;
        int n = s.length();
        if(n == 1)
            return {1};
        
        vector<int> max_freq(128,0);
        vector<int> curr_freq(128,0);
        int start = -1;
        int count = 0;
        
        for(auto x:s)
            max_freq[x]++;
        
        for(int i=0;i<n;i++)
        {
            curr_freq[s[i]]++;
            
            if(curr_freq[s[i]] == 1 && curr_freq[s[i]] <= max_freq[s[i]])
                count++;
            
            if(curr_freq[s[i]] == max_freq[s[i]])
                count--;
            
            if(count == 0)
            {
                res.push_back(i-start);
                start = i;
            }
        }
        
        return res;
        
    }
};