class Solution {
public:
    
    // ANother Approach
    int getSum(int a, int b) {
          while(b != 0)
        {
            unsigned int carry = a&b;
            a = a^b;
            b = carry<<1;
        }
        
        return a;
    }
    
    
    // https://leetcode.com/problems/sum-of-two-integers/discuss/132479/Simple-explanation-on-how-to-arrive-at-the-solution
};