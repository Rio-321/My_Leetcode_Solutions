// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

// Memoization solution

    int Mchain(int i, int j, int *arr, vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(j == i+1)
        {
            dp[i][j] = 0;
            return 0;
        }

        
        int res = INT_MAX;
        
        for(int k=i+1; k<j; k++)
        {
            res = min(res, Mchain(i,k,arr, dp) + Mchain(k,j,arr,dp) + arr[i]*arr[k]*arr[j]);
        }
        
        dp[i][j] = res;
        return res;
        
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return Mchain(0, N-1, arr,dp);        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends