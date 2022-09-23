class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> st;
        
        while(n != 1)
        {
            st.insert(n);
            
            int num = 0;
            
            while(n != 0)
            {
                 num += (n%10)*(n%10);
                 n = n/10;
            }
            
            if(st.count(num) == 1)
                return false;
            
             n = num;
        }
        
        return true;
         
        
        
    }
};