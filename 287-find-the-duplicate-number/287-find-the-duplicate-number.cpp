class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> St;
        for(auto x:nums)
        {
            if(St.find(x)!=St.end())
                return x;
            
            St.insert(x);
        }
        
        return -1;
        
        
    }
};