class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() < 2)
            return s.length();
        
        int res = INT_MIN;
        int left = 0, right = 0;
        int count = 0;
        
        int map[128] = {0};
        
        while(right < s.length())
        {
            if(map[s[right]]++ >= 1)
                count++;
            
            while(count > 0)
            {
                // if(count > res)
                //      res = count;
                
                if(map[s[left]]-- > 1)
                    count--;
                
                left++;
            }
            
            res = max(res, right - left + 1);
            
            
            right++;
        }
        
        return res;
    }
};