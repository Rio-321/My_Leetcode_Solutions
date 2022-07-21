class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int l = 0,  r = 0;
        
        vector<int> count(27,0);
        int ans = 0;
        int maj = 0;
        
        while(r < n)
        {
            count[s[r]-'A']++;
            maj = max(maj, count[s[r]-'A']);
            
            
            while(maj < r-l+1-k)
            {
                
                count[s[l]-'A']--;
                
                maj = *max_element(count.begin(), count.end());

                l++;
            }
            
            ans = max(ans, r-l+1);
            
            r++;
        }
        
        return ans;
        
    }
};