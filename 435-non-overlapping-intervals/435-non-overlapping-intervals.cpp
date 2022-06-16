
class Solution {
public:
    
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









     // int prevLen = intervals[prev][1] - intervals[prev][0] + 1;
//                 int currLen = intervals[i][1] - intervals[i][0] + 1;
                
//                 if(prevLen > currLen)
//                 {
//                     count++;
//                     prev = i;
//                 }
//                 else if(prevLen <= currLen)
//                 {
//                     count++;
//                 }