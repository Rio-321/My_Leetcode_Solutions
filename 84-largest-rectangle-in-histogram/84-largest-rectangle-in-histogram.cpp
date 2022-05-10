class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> prev(n,0);
        vector<int> past(n,0);
        
        // stack<int> St;
        vector<int> St;
        
        for(int i=0;i<n;i++)
        {
            while(!St.empty() && (heights[St.back()]>=heights[i]) )
            {
                St.pop_back();
            }
            
            if(St.empty())
            {
                prev[i] = -1;
            }
            else
            {
                prev[i] = St.back();
            }
            
            St.push_back(i);
            
        }
        
        St.clear();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!St.empty() && ( heights[St.back()] >= heights[i]) )
            {
                St.pop_back();
            }
            
            if(St.empty())
            {
                past[i] = n;
            }
            else
                past[i] = St.back();
            
            St.push_back(i);
        }
        
        // for(auto x:past)
        //     cout<<x<<" ";
        
        int res = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int len  = past[i]-prev[i]-1;
            int area = heights[i]*len;
            
            res = max(res,area);
        }
        
        
        return res;
        
    }
};