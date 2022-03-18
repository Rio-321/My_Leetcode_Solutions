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
    
    int Height(TreeNode* root1)
    {
        if(root1==NULL) return 0;
        
        int left = Height(root1->left);
        int right = Height(root1->right);
        
        res = max(res, left+right);
        
        return max(left,right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int h_left = Height(root->left);
        int h_right = Height(root->right);
        
        // int h = Height(root);
        
        // cout<<res<<"\n";
        // cout<<h_left<<" and "<<h_right<<"\n";
        
        
         res = max(res, h_left + h_right);
        
        return res;
        
    }
};