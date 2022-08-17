class Solution {
public:
    
    bool func(vector<int> &arr, int start, vector<bool> &visited, vector<int> &dp)
    {
          if(start<0 || start >= arr.size())
              return false;
        
         if(visited[start])
             return false;
        
          if(arr[start] == 0)
              return true;
        
         visited[start] = true;
        
        if(dp[start] != -1)
            return dp[start];
            
        
           bool one =  func(arr, arr[start]+start, visited, dp);
        if(one == true)
            return dp[start] = true;
                
           return dp[start] = func(arr,start-arr[start], visited, dp);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        
        int n = arr.size();
        vector<bool> visited(n);
        
        vector<int> dp(n, -1);
        
        return func(arr, start, visited, dp);
    }
};