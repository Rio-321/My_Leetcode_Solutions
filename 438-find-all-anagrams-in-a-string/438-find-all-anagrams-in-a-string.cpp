class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int> P_map;
        
        for(auto x:p)
            P_map[x]++;
        
        int i=0,j=0;
        vector<int> res;
        
        

        
        while(j<s.length())
        {  
            P_map[s[j]]--;
            
            if(P_map[s[j]]==0)
                P_map.erase(s[j]);
            
            
            
            if(j-i+1==p.length())
            {   
               if(P_map.empty())
                   res.push_back(i);
            
                P_map[s[i]]++;
                if(P_map[s[i]]==0)
                    P_map.erase(s[i]);
                
                
                i++;
            }
            
            j++;
        }
        
        
        return res;
    }
};