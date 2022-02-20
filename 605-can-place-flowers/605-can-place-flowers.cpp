class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int len = flowerbed.size();
        int count = 0;
        for(int i=0;i<len;i++)
        {  
           bool prev = false;
           bool next = false;
            
            if(flowerbed[i]==0)
            {
                 if(i==0 || (flowerbed[i-1]==0))
                    prev = true;
                
                 if(i==len-1 || (flowerbed[i+1]==0))
                    next = true;
                
                 if(prev && next)
                    {
                        flowerbed[i] = 1;
                        count++;
                    }  
            }    
                
        }
        
    return count>=n;
        
    }
};