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
    void DFS(TreeNode* root,string &str, int &res)
    {   
        str.push_back(char(root->val + 48));
        
        if(root->left==NULL && root->right==NULL)
        {
            res = res + stoi(str);
            str.pop_back();
            return;
        }
        
         if(root->left!=NULL)
            DFS(root->left,str,res);
         if(root->right!=NULL)
             DFS(root->right,str,res);
        
        str.pop_back();
        
        return; 
    }
    
    int sumNumbers(TreeNode* root) {
        
        int res = 0;
        
        string str = "";
        
        DFS(root,str,res);
        
        return res;
    }
};