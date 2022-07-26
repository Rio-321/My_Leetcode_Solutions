class TrieNode{
 public:
    bool isend;
    TrieNode* child[26];
    
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
    
    bool find_String(int ind, string str, int count)
    {
        TrieNode* curr = root;
        int n = str.size();
        
        for(int i=ind;i<n;i++)
        {
            int num = str[i]-'a';
            
            if(curr->isend == true)
            {
               if(find_String(i, str, count+1))
                   return true;
            }
            
            if(curr->child[num] == NULL)
                return false;
            
            curr = curr->child[num];
            
        }
        
         if(curr->isend == true && count > 1)
             return true;
        
         return false;
    }   
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)    {
        root = new TrieNode();
        
        for(auto str : words)
            insert(str);
        
        vector<string> ans;
        
        
        for(auto str : words)
        {
            if(find_String(0,str,1))
            {
                // cout<<str<<"\n";
                ans.push_back(str);
            }
                
        }
        
        return ans;
    }
};