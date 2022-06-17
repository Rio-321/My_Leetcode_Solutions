class Solution {
public:
    
    // MY SOLUTION
    int getSum(int a, int b) {
        
        string res = "";
        int rem = 0;
        
        for(int i=0;i<32;i++)
        {  
            if(((a>>i & 1) & (b>>i & 1))==1)
            {   
                if(rem==1)
                {
                    res.push_back('1');
                    rem = 1;
                }
                else
                {
                    res.push_back('0');
                    rem = 1;
                }
            }
            else if(((a>>i & 1)|(b>>i & 1))==1)
            {
                
                if(rem==1)
                {
                    res.push_back('0');
                    rem = 1;
                }
                else
                {
                    res.push_back('1');
                    rem = 0;
                }
            }
            else if(((a>>i & 1)|(b>>i & 1))==0)
            {
                if(rem == 1)
                {
                    res.push_back('1');
                    rem = 0;
                }
                else
                {
                    res.push_back('0');
                    rem = 0;
                }
            }
            

            
        }
        
        
        int pow = 1;
        int ans = 0;
        
        for(int i=0;i<res.length();i++)
        {
            if(res[i]=='1')
            {
                ans = ans + (1<<i);
            }
        }
        
        return ans;
        
        
    }
};