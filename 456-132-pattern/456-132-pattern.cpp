class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
       int n = nums.size();
       vector<int> mini(n);
        
        mini[0] = nums[0];
       
        for(int i=1;i<n;i++)
        {  
            mini[i] = min(nums[i], mini[i-1]);
            
        }
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(mini[i]<nums[i])
            {
              while(!st.empty() && st.top()<=mini[i])
                  st.pop();
                
              if(!st.empty() && st.top()<nums[i])
                  return true;
                
                st.push(nums[i]);
            }
        }
        
        return false;
        
    }
};