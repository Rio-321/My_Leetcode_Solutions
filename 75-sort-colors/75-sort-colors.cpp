class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        //My Approach
        int n = nums.size();
        vector<int> ans(n,-1);
        int zero = -1, one = -1, two = -1;
        
        for(auto x:nums)
        {
            if(x == 2)
            {
               two++;
               nums[two] = 2;
            }
            else if(x == 1)
            {
                two++;
                one++;
                nums[two] = nums[one];
                // swap(ans[one], ans[two]);
                nums[one] = 1;
            }
            else
            {
                zero++;
                one++;
                two++;
                nums[two] = nums[one];
                nums[one] = nums[zero];
                nums[zero] = 0;
            }
        }
        
        // cout<<zero<<" "<<one<<" "<<two<<"\n";
        
        // for(auto x:ans)
        //     cout<<x<<" ";
        
        // for(int i=0;i<n;i++)
        //     nums[i] = ans[i];
        
        // return nums;
    }
};