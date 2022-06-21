// MY SOLUTION

class Solution {
public:
    
    // good solution - https://leetcode.com/problems/frog-jump/discuss/1672029/C%2B%2B-or-HashMap-or-Simple-solution-and-explanation
    
    
bool canCross(vector<int>& stones) {
        
    int n = stones.size();
    map<int, set<int>> mp;
    
    mp[stones[0]+1].insert(1);
    
    for(int i=1;i<n;i++)
    {
        if( mp.find(stones[i]) != mp.end())
        {
            
            int pos = stones[i];
            for(auto x: mp[pos])
            {
                mp[pos + x].insert(x);
                mp[pos + x + 1].insert(x + 1);
                mp[pos + x -1].insert(x - 1);
            }
            
        }
        
    }
    
    if(mp.find(stones[n-1]) != mp.end())
        return true;
    else
        return false;
     
    }
};