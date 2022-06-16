
bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}

class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(), comp);
        
        int count = 0;
        int prev = 0;
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[prev][1] > intervals[i][0]  )
            {
                count++;   
            }
            else
            {
                prev = i;
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