class Solution {
public:
    
    bool isPossible(vector<int>& nums, int maxOperations,int penalty)
    {
        int operations = 0;
        
        for(auto x:nums)
        {
            int opr = x/penalty;
            
            if(x%penalty==0)
                opr--;
            
            operations += opr;
        }
        
        if(operations<=maxOperations)
            return true;
        else
            return false;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        
       int low = 1, high = *max_element(nums.begin(),nums.end());
        
       int res = high;
       
        while(low<=high)
        {
            int penalty = low+(high-low)/2;
            
            if(isPossible(nums,maxOperations,penalty))
            {
                high = penalty-1;
                res = penalty;
            }
                
            else
                low = penalty+1;
        }
        
        
        return res;
        
        
    }
};