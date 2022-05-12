class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i=0,j=0;
        
        deque<int> res;
        
        vector<int> ans;
        
        while(j<nums.size())
        {   
            while(!res.empty() && nums[res.back()]<nums[j])
                res.pop_back();
            
            res.push_back(j);
            
             if(res.front()<i)
                res.pop_front();
            
            if(j-i+1==k)
            { 

                
                ans.push_back(nums[res.front()]);
                
                i++;
                
            }
            
            j++;
            
            
        }
        
        return ans;
        
    }
    
    
};