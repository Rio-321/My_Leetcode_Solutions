/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    
    TreeNode* root;
    vector<int> nodes;
    int n;
    queue<TreeNode*> q; 
    int i;
    
    BSTIterator(TreeNode* root) 
    {
        this->root = root;
        
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            nodes.push_back(curr->val);
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
        
        n = nodes.size();
        i = -1;
        sort(nodes.begin(), nodes.end());

    }

    
    int next() {
        i++;
        return nodes[i];
    }
    
    bool hasNext() {
        if(i == n-1)
            return false;
        
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */