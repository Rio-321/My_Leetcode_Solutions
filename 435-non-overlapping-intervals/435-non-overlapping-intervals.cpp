
class Solution {
public:
    
    // by sorting according to first element
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end());
        
        int count = 0;
        int prev = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(prev > intervals[i][0] )
            {
                count++;  
                prev = min(prev, intervals[i][1]);
                
            }
            else
            {
                prev = intervals[i][1];
            }
        }
        
        return count;
    }
};
