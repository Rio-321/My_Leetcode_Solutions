class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> q;
        unordered_set<int> st;
        q.push(0);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            st.insert(curr);
            
            for(auto x:rooms[curr])
            {
                if(st.find(x)==st.end())
                    q.push(x);
            }
        }
        
        if(st.size()==rooms.size())
            return true;
        else
            return false;
    }
};