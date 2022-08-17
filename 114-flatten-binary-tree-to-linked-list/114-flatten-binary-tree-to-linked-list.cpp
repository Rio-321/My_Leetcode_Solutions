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

    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return;
        
        
            cout << root->val << "\n";
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            
            TreeNode *node = root;
            
            while(node->right!=NULL)
            {
                node = node->right;
            }
            
            node->right = temp;
            
            flatten(root->right);
        
        
        return;
    }
};



// Best Solution - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/288414/C%2B%2B-solution-beats-100