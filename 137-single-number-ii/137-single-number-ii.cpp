class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> bits(32,0);
        int res = 0;
        long long pow = 1;
        
        for(int i=0;i<32;i++)
        {
            int count = 0;
            
            for(auto x:nums)
                if(((x)&(1<<i)) !=0)
                    count++;
            
            if(count%3 == 1)
                bits[i] = 1;
        }
        
        
        
        for(int i=0;i<32;i++)
        {
            cout<<bits[i]<<" ";
            if(bits[i]==1)
                res = res + (1<<i);
        }
            
        
        return res;
    }
};