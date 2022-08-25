class Solution {
public:
    
    int countPrimes(int n) 
    {
         if(n <= 2)
               return 0;
         if(n == 3)
            return 1;
        
        int count = 0;
        
         vector<bool> primes(n+1, true);
         
         for(int i=2;i<n;i++)
         {
              if(primes[i] == true)
              {
                  count++;
                  
                  for(int j=2*i;j<n;j = j+i)
                      primes[j] = false;
              }
         }
        
        return count;
    }
};