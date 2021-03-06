/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         //if the root is same as p or q
//         if(root->val == p->val || root->val==q->val)
//             return root;
        
//         // if both are less than curr node
//         if(p->val < root->val && q->val < root->val)
//             return lowestCommonAncestor(root->left,p,q);
        
//         //if both are greater than curr node
//         if(p->val > root->val && q->val > root->val)
//             return lowestCommonAncestor(root->right,p,q);
        
//         //one is less and one is greater
//          return root;
        
        
        //ANOTHER SOLUTION
        
        while((root->val - p->val) * (root->val - q->val)  > 0)
        {
            if(root->val > p->val)
                root = root->left;
            else
                root = root->right;
        }
        
        return root;
        
        
        
    }
};