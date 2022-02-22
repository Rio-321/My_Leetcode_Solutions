class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int tot_gas = 0;
        for(int i=0;i<n;i++)
            tot_gas+=(gas[i]-cost[i]);
        
        
        if(tot_gas<0)
            return -1;
        
        
            for(int i=0;i<n;i++)
            {   
                int ind = i;
                
                if(gas[i]>=cost[i])
                {   
                    // cout<<i<<" ";
                    long long int rem_fuel  = gas[i]-cost[i];
                    bool flag = true;
                    for(int j=(i+1)%n; j!=i; j=(j+1)%n)
                    {
                        rem_fuel = rem_fuel + (gas[j]-cost[j]);
                        
                        if(rem_fuel<0)
                        {  
                            flag = false;
                            i = j;
                            break;
                            
                        }
                        // else
                            // rem_fuel = rem_fuel - cost[j];
                            
                    }
                    
                    if(flag==true)
                        return i;
                    
                    if(i+1<=ind)
                        break;
                    
                }
                
                
            }
            
            return -1;

    }
};