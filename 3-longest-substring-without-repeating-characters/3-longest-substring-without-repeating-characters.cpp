class Solution {
public:
    // https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    
    
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() < 2)
              return s.size();
          
        vector<int> freq(128, 0);
        
        int left = 0, end = 0;
        int count = 0;
        int ans = 0;
        
        while(end < s.size())
        {
            freq[s[end]]++;
            
            if(freq[s[end]] > 1)
                count++;
            
             while(count > 0)
             {
                 freq[s[left]]--;
                 
                 if(freq[s[left]] >= 1)
                     count--;
                 
                 left++;
             }
            
             ans = max(ans, end-left+1);
             end++;
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         if(s.length() < 2)
//             return s.length();
        
//         int res = INT_MIN;
//         int left = 0, right = 0;
//         int count = 0;
        
//         int map[128] = {0};
        
//         while(right < s.length())
//         {
//             if(map[s[right]]++ >= 1)
//                 count++;
            
//             while(count > 0)
//             {
//                 if(map[s[left]]-- > 1)
//                     count--;
                
//                 left++;
//             }
            
//             res = max(res, right - left + 1);
            
            
//             right++;
//         }
        
//         return res;
    }
};