class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
      
        int ans = 0;
        while(true)
        {
            if(arr.size() == 2)
            {
                ans += arr[0]*arr[1];
                return ans;
            }
            
            int mini = INT_MAX;
            int ind = -1;
            
            for(int i=0;i<arr.size()-1;i++)
            {
                if(arr[i]*arr[i+1] < mini)
                 {   
                    mini = arr[i]*arr[i+1];
                    ind = i;
                 }                
            }
            
            ans += arr[ind]*arr[ind+1];
            if(min(arr[ind], arr[ind+1]) == arr[ind])
                    arr.erase(arr.begin()+ind);
            else
                arr.erase(arr.begin()+ind+1);
        }
        
        return ans;
    }
};