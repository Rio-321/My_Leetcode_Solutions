class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,-1);
        int zero = -1, one = -1, two = -1;
        
        for(auto x:nums)
        {
            if(x == 2)
            {
               two++;
               ans[two] = 2;
            }
            else if(x == 1)
            {
                two++;
                one++;
                ans[two] = ans[one];
                // swap(ans[one], ans[two]);
                ans[one] = 1;
            }
            else
            {
                zero++;
                one++;
                two++;
                ans[two] = ans[one];
                ans[one] = ans[zero];
                ans[zero] = 0;
            }
        }
        
        // cout<<zero<<" "<<one<<" "<<two<<"\n";
        
        for(auto x:ans)
            cout<<x<<" ";
        
        for(int i=0;i<n;i++)
            nums[i] = ans[i];
        
        // return nums;
    }
};