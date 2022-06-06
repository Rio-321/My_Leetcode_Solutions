class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        if(nums.size()<2) return;
        int i=0;
        int zero = -1, one = -1;
        while(i<nums.size())
        {
           if(nums[i]==2)
                 i++;
            else if(nums[i]==0)
            {
                zero++;
                
                if(nums[zero]!=1)
                  one++;
                if(zero<i)
                swap(nums[i], nums[zero]);
                else
                    i++;
            }
            else
            {
                one++;
                if(one<i)
                    swap(nums[i], nums[one]);
                else
                    i++;
                
            }
            
            // cout<<zero<<" "<<one<<"\n";
        }
    }
};