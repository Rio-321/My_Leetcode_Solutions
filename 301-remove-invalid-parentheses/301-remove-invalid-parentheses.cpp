class Solution {
public:
    vector<string> ans;
    set<string> st;
    
    int min_removes(string str)
    {
        int count = 0;
        int remove = 0;
         for(auto x:str)
        {
            if(x =='(')
                count++;
            else if(x == ')')
                count--;
            
            if(count < 0)
            {
                remove++;
                count = 0;
            }      
        }
        
        remove = remove + count;
        
        return remove;
    }
    
    void func(string str, int removed)
    {
        
        if(st.find(str) != st.end())
            return;
        
        st.insert(str);
        
        if(removed == 0)
        {
            int needed_removes = min_removes(str);
            if(needed_removes == 0)
                ans.push_back(str);
            
            return;
        }
        
        
        for(int i=0; i<str.length(); i++)
        {
            string leftPart = str.substr(0,i);
            string rightPart = str.substr(i+1);
            string join = leftPart + rightPart;
            func(join, removed-1);
        }
            
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        
        int min_removals = min_removes(s);
        
        func(s, min_removals);

        return ans;
    }
};