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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->val>=low && curr->val<=high)
                ans += curr->val;
            
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
                
        }
        
        return ans;
    }
};