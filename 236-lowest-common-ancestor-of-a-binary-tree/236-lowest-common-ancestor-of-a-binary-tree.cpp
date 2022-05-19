/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 bool find_path(TreeNode* root,TreeNode* x,vector<TreeNode*> &path)
 {
     if(root==NULL) return false;
     
     path.push_back(root);
     
     if(root==x) return true;
     
     if(find_path(root->left,x,path) || find_path(root->right,x,path) )
         return true;
     
     path.pop_back();
     return false;   
 }



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> path1, path2;
        
        find_path(root,p,path1);
        find_path(root,q,path2);

        

        int i=1;
        
        for(;i<path1.size() && i<path2.size();i++)
        {
            if(path1[i]->val != path2[i]->val)
                return path1[i-1];
        }
        i--;
        
        return path1[i]; 
    }
};