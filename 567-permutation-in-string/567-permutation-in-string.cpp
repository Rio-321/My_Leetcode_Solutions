class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n2<n1)
            return false;
        
        unordered_map<char,int> mp;
        for(auto ch:s1)
            mp[ch]++;
        
        
        int i=0;
        int j=0;
        while(i<n2)
        {
            mp[s2[i]]--;
            if(mp[s2[i]]==0)
                mp.erase(s2[i]);
            
            if(i-j+1==n1)
            {
                if(mp.size()==0)
                    return true;
                
                mp[s2[j]]++;
                if(mp[s2[j]]==0)
                    mp.erase(s2[j]);
                
                j++;
            }
            
            i++;
        }
        
        return false;
    }
};