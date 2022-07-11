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
    pair<int,int> findSum(TreeNode* root, map<TreeNode*, pair<int,int>> &dp)
    {
        if(!root)
            return {0, 0};
        
        if(dp.find(root) != dp.end())
            return dp[root];
        
        
        dp[root].first = root->val + findSum(root->left,dp).second + findSum(root->right, dp).second;
            
            
        dp[root].second = max(findSum(root->left,dp).first, findSum(root->left,dp).second) + max(findSum(root->right,dp).first, findSum(root->right,dp).second);
        
        return dp[root];
    }
    
    int rob(TreeNode* root) {
        
        map<TreeNode*, pair<int,int>> dp;
        
        pair<int,int> ans = findSum(root,dp);
        
        return max(ans.first, ans.second);
        
    }
};