class TrieNode{
public:
    TrieNode* child[26];
    bool isend;
    
     TrieNode() {
        
        isend = false;
        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
    
};

class Trie {
public:
    
    TrieNode* root;
    
    Trie()
    {
          root = new TrieNode();
    }
    
    void insert(string word) {
        
        int n = word.length();
        TrieNode* curr = root;
        for(int i=0;i<n;i++)
        {   
            int ind = word[i]-'a';
            
            if(curr->child[ind]==NULL)
                curr->child[ind] = new TrieNode();
            
            curr = curr->child[ind];
        }
        
        curr->isend = true;
    }
    
    bool search(string word) {
        
        TrieNode* curr = root;
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            int ind = word[i]-'a';
            
            if(curr->child[ind] == NULL)
                return false;
            
            curr = curr->child[ind];
        }
        
        if(curr->isend == true)
            return true;
        else 
            return false;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* curr = root;
        int n = prefix.length();
        
        for(int i=0;i<n;i++)
        {
            int ind = prefix[i]-'a';
            if(curr->child[ind] == NULL)
                 return false;
            
            curr = curr->child[ind];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */