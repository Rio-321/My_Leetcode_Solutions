class Solution {
public:
    
    bool find_second(unordered_map<string, vector<pair<double,string>>> &mp, string f, string s,double res, unordered_set<string> &visited, vector<double> &ans)
    {     
          visited.insert(f);
        
          if(f==s)
          {
             ans.push_back(res);
              return true;
          }
              
          for(auto x:mp[f])
          {
              if(visited.find(x.second)==visited.end())  //not visited
                  if(find_second(mp,x.second,s,res*x.first,visited,ans))
                      return true;
          }
        
        return false;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        
        unordered_map<string, vector<pair<double,string>>> mp;
        
        
        vector<double> ans;
        
        for(int i=0;i<n;i++)
        {    
            string first =  equations[i][0];
            string second = equations[i][1];
            
            mp[first].push_back({values[i],second});
            mp[second].push_back({1/values[i], first});
        }
        
        
        
        // for(auto x:mp)
        // {
        //    cout<<x.first<<" - ";
        //    for(auto y:x.second)
        //        cout<<y.first<<" "<<y.second<<" |";
        //    cout<<"\n";
        // }
            
        
        for(int i=0;i<queries.size();i++)
        {
            string f = queries[i][0];
            string s = queries[i][1];
            
            if(mp.find(f)==mp.end() || mp.find(s)==mp.end())
            {
                ans.push_back(-1.0);
            }
            else
            {
                double res = 1;
                 unordered_set<string> visited;
                 if(!find_second(mp,f,s,res, visited,ans))
                     ans.push_back(-1.0);
            }
            
//             if(mp.find(f)!=mp.end() && mp.find(s)!=mp.end())
//             {
                 
//             }
//             else
//             {
//                 ans.push_back(-1.0);
//             }
            
        
        }
        
        
        return ans;

        
    }
};
