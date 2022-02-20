class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int len = flowerbed.size();
        int count = 0;
        bool prev = false, next = false;
        for(int i=0;i<len;i++)
        {  
           prev = false;
           next = false;
         
            if(flowerbed[i]==1)
                continue;
            
            // cout<<i<<" ";
         
            if(i==0)
                prev = true;
            else if(i>0)
            {
                if(flowerbed[i-1]==0)
                    prev = true;
                else
                    prev = false;
            }
         
         
            if(i==len-1)
                next = true;
            else if(i<len-1)
            {
                if(flowerbed[i+1]==0)
                    next = true;
                else
                    next = false;
            }
                
                
            if(prev==true && next==true)
            {
                flowerbed[i] = 1;
                count++;
                cout<<i<<" ";
            }
                // count++;
            
            
                
        }
        
        
        // cout<<count<<"\n";
        
        
    if(count>=n)
        return true;
    else
        return false;
        
    }
};