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
    void print_path(TreeNode* root, vector<string> &res, string &path)
    {   
        if(root==NULL) return;
        
        string temp = to_string(root->val);
        path += temp ;
        cout<<path<<" ";
        
        if(root->left==NULL && root->right==NULL)
        {   
            // path.erase(path.length()-2);
            res.push_back(path);
            path.erase(path.length()-temp.length());
            return;
        }
        
        path += "->";
        
        
        print_path(root->left,res,path);
        print_path(root->right,res,path);
          
        path.erase(path.length()-temp.length()-2);
         return;
         
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        string path="";
        
        print_path(root,res,path);
        
        return res;
    }
};