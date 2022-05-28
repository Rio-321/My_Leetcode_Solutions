class Solution {
public:
    
    bool is_possible(vector<int> &weights, int days, int mid)
    {
        int res = 0;
        int i=0;
        int cap = mid;
        
        while(i<weights.size())
        {   
            if(weights[i]>mid)
                return false;
            
            if(cap>=weights[i])
            {
                cap -= weights[i];
                i++;
            }
            else
            {
                cap = mid;
                res++;
                
                // if(mid==1)
                    // cout<<res<<" ";
            }
                
        }
        res++;
        
        if(res<=days) return true;
        else
            return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        // if day==1  then ans = sum of weights
        
        
        int sum = accumulate(weights.begin(), weights.end(),0);
        
        if(days==1) return sum;
        
        int low = *max_element(weights.begin(), weights.end());
        int high = sum;
        
        int ans = 0;
        // cout<<sum<<"\n";
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;            
            
            if(is_possible(weights,days,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        
        return ans;
        
    }
};