const int mod = 1e9+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max1 = INT_MIN;
        for(int i=1;i<horizontalCuts.size();i++)
        {            
            max1 = max(max1, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
         // cout<<max1<<"\n";
        int max2 = INT_MIN;
        
        for(int i=1;i<verticalCuts.size();i++)
        {   
            max2 = max(max2, verticalCuts[i] - verticalCuts[i-1]);
        }
        // cout<<max2<<"\n";
        
        long long res =  (((long long)max1%mod)*((long long)max2%mod))%mod;
        
        return res;
        
    }
};