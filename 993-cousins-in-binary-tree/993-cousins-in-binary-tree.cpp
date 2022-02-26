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
    
    
    int parx = -1, pary = -1;
    
    int func(TreeNode* root, int &x, int &p, int &par)
    {
        if(root==NULL) 
        {
            par = p;
            return -1;
        }

        if(root->val==x)
        {
            par = p;
            return 0;
        }
            
        
        int left = func(root->left,x,root->val, par);
         if(left != -1)
            return 1+left;
        
        int right = func(root->right,x,root->val,par);
         if(right != -1)
            return 1+right;
        
        return -1;
            
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        int p = -1;
        int heightx = func(root,x,p,parx);
        int heighty = func(root,y,p,pary);
        
        cout<<heightx<<" and "<<heighty<<"\n";
        cout<<parx<<" and "<<pary<<"\n";
        
        
        if(heightx==heighty && parx!=pary)
            return true;
        
        return false;
        
        
        
    }
};