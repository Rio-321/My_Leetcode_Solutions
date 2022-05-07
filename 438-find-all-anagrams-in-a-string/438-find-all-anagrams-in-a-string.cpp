class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        map<char,int> P_map;
        map<char,int> S_map;
        
        for(auto x:p)
            P_map[x]++;
        
        int i=0,j=0;
        vector<int> res;

        
        while(j<s.length())
        {  
            S_map[s[j]]++;
            if(j-i+1==p.length())
            {   
                if(S_map == P_map)
                    res.push_back(i);

                
                S_map[s[i]]--;
                
                if(S_map[s[i]]==0)
                    S_map.erase(s[i]);
                
                i++;
            }
            
            j++;
        }
        
        
        return res;
    }
};