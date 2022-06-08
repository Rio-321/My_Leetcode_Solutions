class FindSumPairs {
public:
    
    vector<int> A;
    vector<int> B;
    unordered_map<long long,long long> mp;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        A = nums1;
        B = nums2;
        
         for(auto x:B)
            mp[x]++;  
    }
    
    void add(int index, int val) {
        
        mp[B[index]]--;
        B[index] = B[index] + val;
        mp[B[index]]++;
    }
    
    int count(int tot) {
        
        long long count = 0;       
        
        for(int i=0;i<A.size();i++)
        {
            if(mp.find(tot-A[i])!=mp.end())
                count += mp[tot-A[i]];

        }
        
        return count;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */