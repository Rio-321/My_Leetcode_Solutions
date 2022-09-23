class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five = 0, ten = 0;
        for(auto x: bills)
        {
            if(x == 5)
            {
                five++;
                continue;
            }
            else if(x == 10)
            {
                if(five < 1) return false;
                
                five--;
                ten++;
            }
            else if(x == 20)
            {
              if(ten > 0)
              {
                  if(five < 1) return false;
                  
                  ten--;
                  five--;
              }
            else
            {
                if(five < 3) return false;
                five = five-3;
            }
              
            }
        }
        
        return true;
        
    }
};