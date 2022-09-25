class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        
        int n = arr.size();

        int targetSum = k * threshold;
        int currentSum = 0;
        
        for(int i=0;i<k;i++)
            currentSum = currentSum + arr[i];
        

        int count = 0;
        
        if(currentSum >= targetSum)
             count++;
        
        
        int l = 0;
        for(int i=k;i<n;i++)
        {
            currentSum = currentSum - arr[l] + arr[i];
            
            if(currentSum >= targetSum)
                count++;
            
            l++;
        }
        
        
        
        return count;
            
            
    }
};