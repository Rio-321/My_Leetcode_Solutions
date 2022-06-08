class FindSumPairs {
public:
    
    vector<int> A;
    vector<int> B;
    map<int,int> first;
    unordered_map<long long,long long> mp;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        A = nums1;
        B = nums2;
        
        for(auto x:A)
            first[x]++;
        
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
        
        for(auto x:first)
        {
            if(x.first>=tot)
                break;
            
            if(mp.count(tot-x.first))
                count += mp[tot-x.first]*x.second;
        }
        
//         for(int i=0;i<A.size() && A[i]<tot;i++)
//         {
//             if(mp.find(tot-A[i])!=mp.end())
//                 count += mp[tot-A[i]];

//         }
        
        return count;
        
    }
};


// soln link - https://leetcode.com/problems/finding-pairs-with-a-certain-sum/discuss/1222759/C%2B%2B-explained-solution-using-map-hashmap-oror-fatser-than-99.5

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */