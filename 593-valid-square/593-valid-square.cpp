class Solution {
public:
    
    double distance(vector<int> a, vector<int> b)
    {
       double dist  = (b[0] -  a[0])*(b[0] -  a[0])   +  (b[1] - a[1])*(b[1] - a[1]);
        
        return dist;
    }
    
    double slope(vector<int> a, vector<int> b)
    {
        return ((b[1] - a[1])*1.00)/(b[0] - a[0]);
    }
    
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        map<int,int> mp;
        
        int d1 = distance(p1,p2); mp[d1]++;
        int d2 = distance(p1,p3); mp[d2]++;
        int d3 = distance(p1,p4); mp[d3]++;
        int d4 = distance(p2,p3); mp[d4]++;
        int d5 = distance(p2,p4); mp[d5]++;
        int d6 = distance(p3,p4); mp[d6]++;
        
        
        if(mp.size() != 2)
            return false;
        
        
        if(mp.rbegin()->first != mp.begin()->first * 2)
            return false;
        
        
        return true;
            
    }
    // https://www.youtube.com/watch?v=B51j1jjTVWk
};