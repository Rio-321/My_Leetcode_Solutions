class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n2<n1)
            return false;
        
        // unordered_map<char,int> mp;
        int freq[26] = {0};
        for(auto ch:s1)
            freq[ch-'a']++;
        
        
        int i=0;
        int j=0;
        while(i<n2)
        {
            freq[s2[i]-'a']--;
            // if(mp[s2[i]]==0)
            //     mp.erase(s2[i]);
            
            if(i-j+1==n1)
            {
                bool flag = 1;
                for(int k=0;k<26;k++)
                {
                    if(freq[k]!=0)
                        flag = 0;
                }
                
                if(flag==1)
                    return true;
                
                
                // if(mp.size()==0)
                //     return true;
                
                freq[s2[j]-'a']++;
                // if(mp[s2[j]]==0)
                //     mp.erase(s2[j]);
                
                j++;
            }
            
            i++;
        }
        
        return false;
    }
};