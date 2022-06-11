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
    int res = 0;
    
    void check(TreeNode* root)
    {
        if(root->left!=NULL)
        {
            if(root->left->left==NULL && root->left->right==NULL)
            {
                res = res + root->left->val;
            }
            else
            {
                check(root->left);
            }
        }
        
        if(root->right!=NULL)
        {
            check(root->right);
        }
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        check(root);
        
        return res;
            
    }
};