class Solution {
public:
   int GCD(int a, int b)
    {
        if(b==0) return a;
        else
            return GCD(b,a%b);
    }
    
    int countPairs(vector<int>& nums, int k) {
        
        unordered_map<int,vector<int>> mp;
        
        int count = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
            
//             if(mp.find(nums[i])!=mp.end())
//             {
//                 for(auto x: mp[nums[i]])
//                 {
//                     if((x*i)%k == 0)
//                         count++;
//                 }
//             }
            
            
            
        }
        
        
        vector<int> vec;
        for(int i=1;i*i<=k;i++)
        {
            if(k%i==0) vec.push_back(i);
            if(k%i==0 && k/i!=i) vec.push_back(k/i);
        }
        
        for(auto x:mp)
        {
            unordered_map<int,int> m;
            for(auto ind:x.second)
            {   
                
                count = count + m[k/GCD(k,ind)];
                
                for(auto j:vec)
                    if(ind%j==0) m[j]++;
            }
        }
        
        return count;
    }
};