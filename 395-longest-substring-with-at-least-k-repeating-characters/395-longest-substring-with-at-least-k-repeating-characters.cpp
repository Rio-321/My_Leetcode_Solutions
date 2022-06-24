class Solution {
public:
    
    // Sliding window solution
    // https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/722300/C%2B%2B-O(n)-Sliding-Window-Explanation-with-approach
    
    // Recursion Solution
    // https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-    characters/discuss/614714/C%2B%2B-Divide-and-Conquer-Solution-with-Explanation
    
    
    // Below is recursion solution
    
    int solve(int start, int end, int k, string &s)
    {
        vector<int> freq(128, 0);
        
        for(int i=start; i<=end; i++)
        {
            freq[s[i]]++;
        }
        
        bool flag = true;
        
        for(int i=start; i<=end; i++)
        {
            if(freq[s[i]] < k)
                flag = false;
        }
        
        if(flag == true)
            return end - start + 1;
        
        for(int i=start; i<=end; i++)
        {
            if(freq[s[i]] > 0 && freq[s[i]] < k)
            {
                int left = solve(start, i-1, k, s);
                int right = solve(i+1, end, k, s);
                
                return max(left, right);
            }
        }
        
        return end - start + 1;
        
    }
    
    
    int longestSubstring(string s, int k) {
        
      return solve(0, s.length()-1, k, s);
    }
};