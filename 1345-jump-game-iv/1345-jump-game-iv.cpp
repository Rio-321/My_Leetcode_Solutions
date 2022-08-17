class Solution {
public:
    
    int BFS(int i, unordered_map<int, vector<int>> &mp, int n, vector<int> &arr)
    {
        
        queue<int> q;
        q.push(i);
        int k = 0;
        
        vector<bool> visited(n);
        visited[i] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int count = 0;count<size; count++)
            {
                int curr = q.front();
                q.pop();
                
                if(curr == n-1)
                    return k;
                
                if(curr+1<n && !visited[curr+1])
                {
                   q.push(curr+1);
                    visited[curr+1] = true;
                }
                
                if(curr-1 >=0 && !visited[curr-1])
                {
                    q.push(curr-1);
                    visited[curr-1] = true;
                }
                
                for(auto &x : mp[arr[curr]])
                {  
                     if(!visited[x])
                     {
                         visited[x] = true;
                         q.push(x);
                     }
                }
                
                mp[arr[curr]].clear();
                
            }
            
            k++;
        }
        
        return k;
    }
    
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int,vector<int>> mp;
        
        
        for(int i=0;i<n;i++)
            mp[arr[i]].push_back(i);
        
//         for(auto &x: mp)
//         {
//             cout << x.first << " - ";
//             for(auto &y : x.second)
//                 cout << y << " ";
            
//             cout <<"\n";
//         }
        
        
        int res = BFS(0, mp, n, arr);
        
        return res;
        
    }
};