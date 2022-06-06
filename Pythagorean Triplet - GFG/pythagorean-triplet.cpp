// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    sort(arr, arr+n);
	    for(int i=0;i<n;i++)
	       arr[i] = arr[i]*arr[i];
	       
	    for(int i=n-1;i>1;i--)
	    {
	       // int res = arr[i]*arr[i];
	        int left = 0,right = i-1;
	        
	        while(left<right)
	        {
	            int sum = arr[left]+arr[right];
	            if(sum==arr[i])
	                return true;
	            if(sum>arr[i])
	               right--;
	           else
	               left++;
	        }
	    }
	    
	    
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends