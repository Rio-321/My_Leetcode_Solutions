class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        vector<int> freq(2, 0);
        queue<int> q;
        
        for(auto &x : students)
        {
            freq[x]++;
            q.push(x);
        }
        int i = 0;
        
        while(!q.empty())
        {
            if(q.front() == sandwiches[i])
            {
                freq[q.front()]--;
                q.pop();
                i++;
            }
            else
            {
                if(freq[0] == 0 || freq[1] == 0)
                    return q.size();
                
                q.push(q.front());
                q.pop();
            }
              
        }
        
        
        return q.size();
    }
};