class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int res = 0;
        int count[101] = {};
        
        for(auto x:nums)
            count[x]++;
        
        for(int i=1;i<101;i++)
        {
            if(count[i]>1)
                res += (count[i]*(count[i]-1))/2;
                
        }
        
        
        
        return res;
        
    }
};