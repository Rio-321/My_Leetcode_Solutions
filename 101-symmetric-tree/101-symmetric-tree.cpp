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
    bool is_mirror(TreeNode* leftR, TreeNode* rightR)
    {   
        if(leftR==NULL && rightR==NULL)
            return true;
        
        if(leftR==NULL || rightR==NULL)
            return false;
        
        cout<<"P ";
        
        if(leftR->val==rightR->val)
            return (is_mirror(leftR->left,rightR->right) && is_mirror(leftR->right,rightR->left));
        else
            return false;
    }
      bool isSymmetric(TreeNode* root) {
        
        return is_mirror(root->left, root->right);
    }
};