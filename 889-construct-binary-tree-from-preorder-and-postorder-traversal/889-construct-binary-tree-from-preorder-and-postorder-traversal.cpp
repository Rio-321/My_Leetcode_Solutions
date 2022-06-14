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
    
    // Optimal Solution
    
    int preindex = 0, postindex = 0;
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        TreeNode* root = new TreeNode(preorder[preindex++]);
        
        if(root->val != postorder[postindex])
            root->left = constructFromPrePost(preorder,postorder);
        if(root->val != postorder[postindex])
            root->right = constructFromPrePost(preorder,postorder);
        postindex++;
        
        return root;
    }
};



// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/821268/C-Construct-tree-using-preorder-traversal-first