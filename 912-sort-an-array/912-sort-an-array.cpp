class Solution {
public:
    
//     int partition(vector<int> &nums, int l, int r)
//     {
//         int piv = nums[r];
//         int ind = l;
        
//         for(int i=l;i<r;i++)
//         {
//             if(nums[i] <= piv)
//             {
//                 swap(nums[ind], nums[i]);
//                 ind++;
//             }
//         }
        
//         swap(nums[ind], nums[r]);
        
//         return ind;
//     }
    
//     void QuickSort(vector<int> &nums, int l, int r)
//     {
//         while(l < r)
//         {
//             int p = partition(nums, l, r);
//             QuickSort(nums, l, p-1);
//             QuickSort(nums, p+1, r);
//         }
//     }
   void Merge(vector<int> &arr, int l, int m, int r)
   {
       int n1 = m-l+1;
       int n2 = r-m;
       vector<int> left(n1);
       vector<int> right(n2);
       
       for(int i=0;i<n1;i++)
           left[i] = arr[l+i];
       
       for(int i=0;i<n2;i++)
           right[i] = arr[m+1+i];
       
       int k = l;
       int i = 0, j = 0;
       while(i< n1 || j < n2)
       {
           if(i == n1)
           {
               arr[k] = right[j];
               j++;
               k++;
           }
           else if(j == n2)
           {
               arr[k] = left[i];
               i++;
               k++;
           }
           else if(left[i] < right[j])
           {
               arr[k] = left[i];
               i++;
               k++;
           }
           else
           {
               arr[k] = right[j];
               j++;
               k++;
           }
       }
       
       left.clear();
       right.clear();
       
   }
    
   void MergeSort(vector<int> &arr, int l, int r)
    {
        if(l < r)
        {
            int mid = l + (r-l)/2;
            MergeSort(arr, l, mid);
            MergeSort(arr, mid+1, r);
            Merge(arr, l,mid, r);
        }
    }
    
    vector<int> sortArray(vector<int>& arr) {
        
        int n = arr.size();
        
        MergeSort(arr, 0, n-1);
        
        return arr;
    }
};