class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      
        int low = 1;
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int cnt = 0;
            
            for(auto x:nums)
                if(x<=mid)
                    cnt++;
            
            if(cnt>mid)
                high = mid-1;
            else
                low = mid+1;

        }
        
        return low;
    }
};