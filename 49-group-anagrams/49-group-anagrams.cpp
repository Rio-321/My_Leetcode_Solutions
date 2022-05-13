class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        
        for(auto s:strs)
        {
            string temp = s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto x:mp)
        {   
            vector<string> temp_vect;
            for(auto str:x.second)
            {
                temp_vect.push_back(str);
            }
            
            ans.push_back(temp_vect);
        }
        
        return ans;
    }
};