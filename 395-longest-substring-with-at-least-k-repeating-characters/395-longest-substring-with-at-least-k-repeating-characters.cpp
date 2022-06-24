class Solution {
public:
    
    // Sliding window solution
    // https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/722300/C%2B%2B-O(n)-Sliding-Window-Explanation-with-approach
    int solve(string &s, int uniq, int k)
    {
        int ans = 0;
        
        vector<int> mp(128, 0);
        int left = 0, right = 0;
        int curr_uniq = 0;
        int freq_item = 0;
        
        while(right < s.length())
        {
            if(mp[s[right]] == 0) 
                curr_uniq++;
            
            mp[s[right]]++;
            
            if(mp[s[right]] == k)
                freq_item++;
            
            while(curr_uniq > uniq)
            {
                if(mp[s[left]] == k)
                    freq_item--;
                
                mp[s[left]]--;
                
                if(mp[s[left]] == 0)
                    curr_uniq--;
                
                left++;
            }
            
            if(curr_uniq == freq_item)
            ans = max(ans, right - left + 1);
            
            right++;
        }
        
        return ans;
        
    }
    
    
    int longestSubstring(string s, int k) {
        
       
        int res = 0;
        
        for(int i=1; i <= 26; i ++)
        {
            res = max(res, solve(s, i, k));
            // cout<<res<<"\n";
        }
        
        return res;
            
    }
};