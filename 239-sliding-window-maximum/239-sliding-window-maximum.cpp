class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i=0,j=0;
        map<int,int> mp;
        
        vector<int> res;
        
        while(j<nums.size())
        {   
            mp[nums[j]]++;
            if(j-i+1==k)
            {
                auto it = mp.end();
                it--;
                res.push_back(it->first);
                
                
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                
                i++;
                
            }
            
            
            
            
            j++;
            
            
        }
        
        return res;
        
    }
    
    
};