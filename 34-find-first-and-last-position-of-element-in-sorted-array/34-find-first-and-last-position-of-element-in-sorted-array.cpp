class Solution {
public:
    
    int First_Occure(vector<int> &nums, int x, int low, int high)
    {
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if((nums[mid]==x) && (mid==0 || nums[mid-1]!=nums[mid]))  return mid;
            
            if(nums[mid]>=x)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
    
    int Last_Occure(vector<int> &nums, int x, int low, int high)
    {  
        int n = nums.size();
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid]==x && (mid==n-1 ||nums[mid+1]!=nums[mid]))  return mid;
            
            if(nums[mid]<=x)
                low = mid+1;
            else
                high = mid-1;       
        }
        
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        int n = nums.size();
        int first = First_Occure(nums,target,0,n-1);
        if(first==-1)
                return res;
      
        int second = Last_Occure(nums,target,0,n-1);
        res[0] = first;
        res[1] = second;
        
        return res;     
        
    }
};