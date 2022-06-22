class Solution {
public:
    vector<int> res;
    
    void helper(int ind, string &s, map<string,int> freq, int len, int k)
    {
        
        int i = ind;
        
        while(i<ind+k)
        {
            string temp = s.substr(i, len);
            
            if(freq.find(temp) != freq.end())
            {
                freq[temp]--;
                
                if(freq[temp] == 0)
                    freq.erase(temp);
            }
            else
            {
                return;
            }
            
            i = i + len;
        }
        
        if(freq.size() == 0)
            res.push_back(ind);
    }
    
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.length();
        int k = words.size() * words[0].length();
        int i = 0;   
        

        map<string, int> freq;
        
        for(auto str:words)
            freq[str]++;
        
        
        for(int j=k-1;j<n;j++,i++)
        {
            helper(i, s, freq, words[0].length(), k);
        }
        
        return res;
    }
};