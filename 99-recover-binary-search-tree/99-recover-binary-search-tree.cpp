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
    
    TreeNode* prev,*first,*middle,*last;
    

    void Inorder(TreeNode* root)
    {
        if(root==NULL) return;
        
        Inorder(root->left);
       
        if(prev!=NULL && prev->val > root->val)
        {
            if(first==NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
             
        }
    
        prev = root;
        
        Inorder(root->right);
    }

    
    void recoverTree(TreeNode* root) {
        
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        Inorder(root);
        
        if(first && last)
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val, middle->val);
           
    }
};


// 1st solution - https://leetcode.com/submissions/detail/720401862/