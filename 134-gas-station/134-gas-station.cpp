class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int tot_gas = 0, tot_cost = 0;
        for(int i=0;i<n;i++)
        {
            tot_gas+=gas[i];
            tot_cost+=cost[i];
        }
        
        // cout<<n<<"\n";
        // cout<<tot_gas<<"\n"<<tot_cost<<"\n";
        
        if(tot_gas>=tot_cost)
        {
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
                        rem_fuel = rem_fuel + gas[j];
                        
                        if(rem_fuel<cost[j])
                        {  
                            flag = false;
                            i = j;
                            break;
                            
                        }
                        else
                            rem_fuel = rem_fuel - cost[j];
                            
                    }
                    
                    if(flag==true)
                        return i;
                    
                    if(i+1<=ind)
                        break;
                    
                }
                
                
            }
            
            return -1;
        }
        else
            return -1;
    }
};