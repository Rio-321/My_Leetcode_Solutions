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
    
    int Height(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int left = Height(root->left);
        int right = Height(root->right);
        
        res = max(res, left+right);
        
        return max(left,right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        // int h_left = Height(root->left);
        // int h_right = Height(root->right);
        
        int h = Height(root);
        
        // int res = max(res, h_left + h_right);
        
        return res;
        
    }
};