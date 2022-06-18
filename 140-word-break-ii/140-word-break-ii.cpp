class Solution {
public:
    vector<string>  res;
    
    
    void func(string parent, int index, string s, unordered_set<string> &st)
    {
        if(index==s.length())
        { 
            parent.pop_back();
            res.push_back(parent);
            return;
        }
        
        
        string temp;
        for(int i=index;i<s.length();i++)
        {
            temp += s[i];
            
            if(st.find(temp)!=st.end())
            {
                func(parent + temp + " ", i+1, s, st);
            }
            
        }
        
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        string parent = "";
        func(parent,0,s,st);
      
        return res;
    }
};