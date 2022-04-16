class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int n = arr.size();
        
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + arr[i];
        }
        
        if(sum%3!=0)
            return false;
        else
        {
            int tar = sum/3;
            int cnt = 0;
            int sum1 = 0;
            for(int i=0;i<n;i++)
            {
                sum1 = sum1 + arr[i];
                
                if(sum1==tar)
                {
                    sum1 = 0;
                    cnt++;
                }
                
                if(i<n-1 && cnt==2)
                    return true;
            }
        }
        
        
        return false;
            
        
    }
};