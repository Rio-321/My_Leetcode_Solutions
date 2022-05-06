// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
     queue<long long> ind;
     vector<long long> res;
     
     for(long long i=0;i<K;i++)
     {
         if(A[i]<0)
          ind.push(i);
     }
     
    //  cout<<ind.front()<<"\n";
     
     
     
     for(long long i=K-1;i<N;i++)
     {
         long long f = i-K+1;
         
         if(A[i]<0 && i!=K-1)
            ind.push(i);
         
         if(ind.empty())
            res.push_back(-1);
         else if(ind.front()==f)
         {
             res.push_back(ind.front());
             ind.pop();
         }
         else
         {
            res.push_back(ind.front());
         }
         
     }
     
     for(auto x:res)
     {
         x = A[x];
     }
     
     vector<long long> ans;
     
     for(int i=0;i<res.size();i++)
     { 
        long long x = 0;
        
        if(res[i]!=-1)
        x = A[res[i]];
        
        ans.push_back(x);  
     }
       
     return ans;
                                                 
 }