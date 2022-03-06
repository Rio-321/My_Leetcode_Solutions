class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        int curr,f=nums[0];
        
        if(n==1) return f;
        
        int s=nums[1];
        if(n==2) return max(f, s);
        
        int max_num = nums[0];
    
        for(int i=2;i<n;i++)
        {  
            curr = max_num + nums[i];
            max_num = max(max_num, s);
            f = s;
            s = curr;
            
        }
        return max(f,s);        
    }
};