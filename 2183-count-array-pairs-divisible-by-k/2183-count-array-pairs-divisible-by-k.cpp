class Solution {
public:
    int GCD(int a, int b)
    {
        if(b==0) return a;
        else
            return GCD(b,a%b);
    }
    
    long long countPairs(vector<int>& nums, int k) {
        
        vector<int> vec;
        for(int i=1;i*i<=k;i++)
        {
            if(k%i==0) vec.push_back(i);
            if(k%i==0 && k/i!=i) vec.push_back(k/i);
        }
        
        // for(auto x:vec) cout<<x<<" ";
        
        
        unordered_map<int,int> mp;
        long long sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            int g = GCD(k,nums[i]);
            int rem = k/g;
            
            sum = sum + mp[rem];
            
            for(auto x:vec)
            {
                if(nums[i]%x == 0)
                    mp[x]++;
            }
          
            // cout<<rem<<" ";
        }
        
        return sum;
   
    }
};