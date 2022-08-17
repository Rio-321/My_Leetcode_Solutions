class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        int mini  = 0;
        int maxa = 0;
        int count = 0;
        while(maxa < n)
        {
            for(int i=0;i<ranges.size();i++)
            {
                if(i-ranges[i] <= mini && i+ranges[i] > maxa)
                    maxa = i+ranges[i];
            }
            
            if(mini == maxa)
                return -1;
            
            mini = maxa;
            count++;
        }
        
        return count;
    }
};