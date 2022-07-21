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
    long long sum;
    int count;
    unordered_map<long long, long long> mp;
    
    void solve(TreeNode* root, int targetSum)
    {
        if(!root)
            return;
         
        sum += root->val;
        
        if(mp.count(sum-targetSum))
            count += mp[sum-targetSum];
        
        mp[sum]++;
        
        if(root->left)
            solve(root->left, targetSum);
        
        if(root->right)
            solve(root->right, targetSum);
        
        mp[sum]--;
         
        sum -= root->val;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        sum = 0;
        count = 0;
        
        mp[0] = 1;
        
        solve(root, targetSum);
        
        return count;
    }
};