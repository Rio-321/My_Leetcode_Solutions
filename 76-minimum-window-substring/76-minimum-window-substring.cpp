class Solution {
public:
    // https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    
    
    // Optimal Approach
    string minWindow(string s, string t) {
        
        int res = INT_MAX;
        
        int mp[128] = {0};
        
        string ans = "";
        for(char c:t)
            mp[c]++;
        
        
        int count  = t.length();
       
        
        int left = 0,right = 0, head = 0;
        
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
                    // ans = s.substr(left, right - left + 1);
                    head = left;
                }
                
                mp[s[left]]++;
                
                if(mp[s[left]] > 0)
                    count++;
                
                left++;
            }
            
            right++;
           
        }
        
        
        if(res == INT_MAX)
            return "";
        else
            return s.substr(head, res);
        
    }
};