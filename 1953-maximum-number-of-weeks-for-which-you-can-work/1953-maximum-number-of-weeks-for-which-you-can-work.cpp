class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        
        long long n = milestones.size();
        int MAX = INT_MIN;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            MAX = max(MAX, milestones[i]);
            sum = sum + milestones[i];
        }
        
        if(sum-MAX == MAX) return 2*MAX;
        else if(MAX > sum-MAX) return 2*(sum-MAX)+1;
        else
        {
            return sum;
        }
        
        
    }
};