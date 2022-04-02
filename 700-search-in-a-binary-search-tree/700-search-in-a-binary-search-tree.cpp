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
    TreeNode* search_BST(TreeNode* root,int x)
    {
        while(root!=NULL)
        {
           if(root->val==x)
               return root;
            
            if(root->val > x)
                root = root->left;
            else
                root = root->right;
        }
        
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return search_BST(root,val);
        
    }
};