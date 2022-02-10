// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long  pre_sum = 0;
        long long  max_num = INT_MIN;
        long long  max_sum = INT_MIN;
        
        for(long long  i=0;i<n;i++)
        {
            max_num = max(max_num, (long long )(arr[i]));
            pre_sum = pre_sum + (long long)arr[i];
            max_sum = max(max_sum, pre_sum);
            
            if(pre_sum<0)
            pre_sum = 0;
        }
        
        return max(max_num, max_sum);
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends