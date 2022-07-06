class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        //ANOTHER APPROACH
        int n = nums.size();
        if(n == 1) return true;
        
        int last = n-1;
        
        for(int i=n-2; i>=0;i--)
        {
            if(nums[i]+i >= last)
                last = i;
        }
        
        if(last == 0)
            return true;
        
        return false;
        
    }
};



// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
        
        
//         //MY APPROACH
//         int n = nums.size();
        
//         if(n == 1 ) return true;
//         if(nums[0] == 0) return false;
        
        
//         int maxi = nums[0];
//         int p = maxi;
        
//         int i=1;
        
//         while(i < n)
//         {
            
//             maxi = max(maxi, nums[i]+i);
            
//             if(maxi >= n-1)
//                 return true;
            
            
//             if(i == p)
//             {
//                 if(maxi == p) 
//                         return false;
                
//                 p = maxi;
//             }
            
//             i++;
//         }
        
        
//         return false;
        
//     }
// };