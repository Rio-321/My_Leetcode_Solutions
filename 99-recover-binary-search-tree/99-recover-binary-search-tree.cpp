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
    
    // A Bit optimized than previous
    vector<int> nodes;
    int index=0;
    void Inorder(TreeNode* root, int flag, int &index)
    {
        if(root==NULL) return;
        
        Inorder(root->left,flag,index);
       
        if(flag==1)
        {
               root->val = nodes[index];
               index++;                
        }
        else
             nodes.push_back(root->val);
        
        Inorder(root->right,flag,index);
    }

    void recoverTree(TreeNode* root) {
        
        int index = 0;
        Inorder(root,0,index);
        
        sort(nodes.begin(), nodes.end());
        
        Inorder(root,1,index);
           
    }
};


// 1st solution - https://leetcode.com/submissions/detail/720401862/