class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int l=0,r=n-1;
        
        while(l<=r)
        {
           int mid = (l+r)/2;
            if((mid==n-1||arr[mid]>arr[mid+1]) && (mid==0 || arr[mid]>arr[mid-1])) return mid;
            else
                if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1||arr[mid]<arr[mid+1]))
                    l = mid+1;
            else
                r = mid-1;
        }
        
        return l;
    }
};