// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
    	sort(a,a+n);
    	long long count = 0;
    	for(int i=0;i<n;i++)
    	{   
    	    if(a[i]<0) continue;
    	    long long low = 0,high = i-1;
    	    long long ans = i;
    	    long long x = -1*a[i];
    	    while(low<=high)
    	    {
    	        long long mid = (low+high)/2;
    	        
    	        if(a[mid]>x)
    	        {
    	            ans = mid;
    	            high = mid-1;
    	        }
    	        else
    	        low = mid+1;
    	    }
    	    
    	    count += (i-ans);
    	   // cout<<(i-ans)<<"\n";
    	}
    	
    	return count;
    }   
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends