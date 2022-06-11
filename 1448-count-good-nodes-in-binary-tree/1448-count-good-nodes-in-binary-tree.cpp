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
    
    int goodNodes(TreeNode* root, int maxTill)
    {
        if(root==NULL)
            return 0;
        
        int count = 0;
        if(maxTill <= root->val)
            count = 1;
        
        maxTill = max(maxTill, root->val);
        return goodNodes(root->left,maxTill) + goodNodes(root->right, maxTill) + count;
    }
    
    int goodNodes(TreeNode* root) {
        
     return goodNodes(root,INT_MIN); 
    }
};