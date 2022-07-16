class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n = time.size();
        for(int i=0;i<n;i++)
            time[i] = time[i]%60;
        
        
        // sort(time.begin(), time.end());
        
        int count = 0;
        
        // map<int,int> mp;
        
        vector<int> mp(61, 0);
        
        for(int i=0;i<n;i++)
        {
            
            count = count + mp[60 - time[i]];
            
            
            if(time[i]==0)
                mp[60]++;
            else
            mp[time[i]]++;
        }
        
//         int l = 0, r = n-1;
//         int count = 0;
//         while(l < r)
//         {
//             int sum = time[l] + time[r];
            
//             if(sum == 60 || sum == 0)
//              {  
//                 count++;
                
//                 if(r-1 >= 0 && time[r-1] == time[r])
//                     r--;
//                 else if(l+1 < n && time[l+1] == time[l])
//                     l++;
//                 else
//                 {
//                     l++;
//                     r--;
//                 }

                
//              }
//            else if(sum > 60)
//                 r--;
//             else
//                 l++;
//         }
        
        return count;
    }
};