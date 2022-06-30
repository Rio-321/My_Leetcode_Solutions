class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        int maxa = 0;
        long long  sum = 0;
        long long sum1 = 0;
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0;i<n-1;i++)
        {       
             int diff = heights[i+1] - heights[i];
             if(diff >= 0)
             {
                 if(pq.size() < ladders)
                 {
                    pq.push(diff);  
                    sum1 = sum1 + diff;
                 }  
                 else
                 {
                     if(!pq.empty() && pq.top() < diff)
                     {
                         pq.push(diff);
                         sum1 = sum1 + diff - pq.top();
                         pq.pop();
                         
                     }
                 }
                 
                // maxa = max(maxa, diff);
                sum = sum + diff;
             } 
            else
                continue;
            
            int maxBricks = sum - maxa;
            
           if(sum - sum1 > bricks)
               return i; 
        }
        
        
        return n-1;
    }
};