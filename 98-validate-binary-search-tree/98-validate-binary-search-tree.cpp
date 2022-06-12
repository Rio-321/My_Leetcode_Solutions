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
class Solution {
public:
    
    //small Optimization
    TreeNode *prev = NULL;
    bool isValid = true;
    
    
    void Inorder(TreeNode* root)
    {
        if(root==NULL) return;
        
        // if(!isValid) return;
        
        if(isValid)
              Inorder(root->left);

        
        if(prev!=NULL && prev->val >= root->val) 
        {
            isValid = false;
            return ;
        }
                
        
        prev = root;
        
        if(isValid)
            Inorder(root->right);
           
    }

    bool isValidBST(TreeNode* root) {
        
       Inorder(root);
        return isValid;
    }
};