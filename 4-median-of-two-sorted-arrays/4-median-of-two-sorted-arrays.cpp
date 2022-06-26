class Solution {
public:
    
    // My Approach
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int len = (n1 + n2);
        
        if(len == 1)
        {
            if(n1 == 1)
                return nums1[0];
            else
                return nums2[0];
        }
        
        int ind1 = (len - 1)/2;
        int ind2 = (len + 1)/2;
        
        // cout<<ind2<<"\n";
    
        
        int val1 = 0, val2 = 0;
        
        int i = 0;
        int one = 0, two = 0;
        while(one < n1 && two < n2 && i<=ind2)
        {
            if( nums1[one] > nums2[two])
            {
                if(i == ind1)
                    val1 = nums2[two];
                
                if(i == ind2)
                    val2 = nums2[two];
                
                two++;
                i++;
                
            }
            else
            { 
                if(i == ind1)
                    val1 = nums1[one];
                
                if(i == ind2)
                    val2  = nums1[one];
                
                one++;
                i++;
            }
            
            
        }
        
        while( one < n1 && i <= ind2)
        {
             if(i == ind1)
                    val1 = nums1[one];
                
            if(i == ind2)
                    val2 = nums1[one];
                
              one++;
              i++;
        }
        
        while(two < n2 && i <= ind2)
        {
            if(i == ind1)
                    val1 = nums2[two];
                
            if(i == ind2)
                   val2  = nums2[two];
                
                two++;
                i++;
        }
        
        // cout<<val1<< " "<< val2;
        
        if(len % 2 == 1)
        {
            return (double)val1;
        }
        else
            return (double)(val1 + val2)/2.00;
            
    }
};