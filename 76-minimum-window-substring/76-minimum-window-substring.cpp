class Solution {
public:
    // https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    string minWindow(string s, string t) {
        
        int res = INT_MAX;
        
        unordered_set<char> st(s.begin(), s.end());
        
        string ans = "";
        map<char, int> mp;
        for(char c:t)
            mp[c]++;
        
        int count  = t.length();
        // cout<<mp.size()<<" ";
        
        int left = 0,right = 0;
        
        while(right < s.length())
        {     
            mp[s[right]]--;
            
            if(mp[s[right]] >= 0 )
                count--;
            
            while(count == 0)
            {
                if(right - left + 1 < res)
                {
                    res = right - left + 1;
                    ans = s.substr(left, right - left + 1); 
                }
                
                mp[s[left]]++;
                
                if(mp[s[left]] > 0)
                    count++;
                
                left++;
            }
            
            right++;
                
            // cout<<left<<" "<<right<<" "<<mp.size()<<"\n";
           
        }
        
        // cout<<res;
        
        
        return ans;
        
    }
};