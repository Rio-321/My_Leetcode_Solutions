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
    void print_path(TreeNode* root, vector<string> &res, string path)
    {   
        
        if(root->left==NULL && root->right==NULL)
        {   
            res.push_back(path);
            return;
        }
        
        
        if(root->left)
            print_path(root->left,res, path + "->" + to_string(root->left->val));
        
        if(root->right)
        print_path(root->right,res, path + "->" + to_string(root->right->val));
          
         return;
         
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        // string path="";
        
        if(root==NULL) return res;
        
        print_path(root,res,to_string(root->val));
        
        return res;
    }
};