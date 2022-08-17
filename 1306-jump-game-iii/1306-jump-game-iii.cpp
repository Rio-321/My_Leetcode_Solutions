class Solution {
public:
    
    bool func(vector<int> &arr, int start, vector<bool> &visited)
    {
          if(start<0 || start >= arr.size())
              return false;
        
         if(visited[start])
             return false;
        
          if(arr[start] == 0)
              return true;
        
         visited[start] = true;
            
        
           bool one =  func(arr, arr[start]+start, visited);
        if(one == true)
            return true;
                
           return func(arr,start-arr[start], visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        
        int n = arr.size();
        vector<bool> visited(n);
        
        return func(arr, start, visited);
    }
};