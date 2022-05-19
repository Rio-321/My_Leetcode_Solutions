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
    
    bool is_path(TreeNode* root, int &sum, int &targetSum)
    {   
        if(root==NULL) return false;
        
        sum += root->val;
        
        if(root->left==NULL && root->right==NULL && sum==targetSum)
            return true;
        
        
        if(is_path(root->left,sum,targetSum) || is_path(root->right,sum,targetSum) )
             return true;

        sum -= root->val;
        return false;
            
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;
        bool flag = is_path(root,sum,targetSum)  ? true :  false;
        
        return flag;
    }
};