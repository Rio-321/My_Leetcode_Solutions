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
    TreeNode* getSuccessor(TreeNode* curr)
    {
        curr = curr->right;
        while(curr!=NULL && curr->left!=NULL)
            curr = curr->left;
        
        return curr;
    }
    
    TreeNode* delete_Node(TreeNode* root, int x)
    {   
        if(root==NULL) return root;
        
        if(root->val > x)
            root->left = delete_Node(root->left,x);
        else if(root->val < x)
            root->right = delete_Node(root->right,x);
        else
        {
            if(root->left==NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode* succ = getSuccessor(root);
                root->val = succ->val;
                root->right = delete_Node(root->right,succ->val);
                
            }
            
           
        }
         return root;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int val) {
        
        return delete_Node(root,val);
        // return root;
        
    }
};