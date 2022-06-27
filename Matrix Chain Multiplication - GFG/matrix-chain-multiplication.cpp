// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

// Memoization solution
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        
        for(int gap = 1; gap<N; gap++)
        {
            for(int i=0; i<N && i+gap<N; i++)
            {
                int j = i + gap;
                if(gap == 1)
                   dp[i][j] = 0;
                else
                {
                    dp[i][j] = INT_MAX;
                    for(int k = i+1; k<j; k++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
                    }
                }
                
            }
        }
        return dp[0][N-1];        
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