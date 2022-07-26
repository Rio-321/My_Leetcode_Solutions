class TrieNode{
public:
    TrieNode* child[26];
    bool isend;
    
    TrieNode()
    {
        isend = false;
        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
    
};

class Solution {
public:
    
    TrieNode* root;
    
    void insert(string str)
    {
        TrieNode* curr = root;
        int n = str.size();
        for(int i=0;i<n;i++)
        {
            int num = str[i] - 'a';
            
            if(curr->child[num] == NULL)
            {
                TrieNode* temp = new TrieNode();
                curr->child[num] = temp; 
            }
            
            curr = curr->child[num];
        }
        
        curr->isend = true;
    }
    

    bool is_possible(int ind, string str, vector<int> &dp)
    {   
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int n = str.length();
        
        TrieNode* curr = root;
        
        for(int i=ind;i<n;i++)
        {
            if(curr->isend == true)
            {
                if(is_possible(i, str,dp))
                    return dp[ind] = true;
            }
            
            int num = str[i]-'a';
            
            if(curr->child[num] == NULL)
                return dp[ind] = false;
            else
            {
                curr = curr->child[num];
            }
             
        }
        
        if(curr->isend == true)
            return dp[ind] = true;
        else
            return dp[ind] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        root = new TrieNode();
        
        for(auto str : wordDict)
            insert(str);
        
        
        int n = s.length();
        vector<int> dp(n, -1);
      
        return is_possible(0,s, dp);
    }
};