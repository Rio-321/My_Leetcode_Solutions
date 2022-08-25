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
    
    int ans = INT_MIN;
    
    int func(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int l = func(root->left);
        int r =  func(root->right);
            
        int one = max(root->val, max(l, r) + root->val);
        
        int two = max(one, l+r+root->val);
        
        ans = max(ans, two);
        
        return one;
    }
    
    int maxPathSum(TreeNode* root) {
        
        
        func(root);
        
        return ans;
        
    }
};