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
    
    bool is_subtree(TreeNode *temp, TreeNode* subRoot)
    {  
        if((temp==NULL && subRoot!=NULL)  || (temp!=NULL  && subRoot==NULL))
            return false;
        
        if(temp==NULL && subRoot==NULL) return true;
        
        if(temp->val==subRoot->val && is_subtree(temp->left, subRoot->left) && is_subtree(temp->right, subRoot->right))
            return true;
        else
            return false;
    }
    
    void find_node(TreeNode* root, TreeNode* subRoot,vector<TreeNode*> &same_vertex)
    {
        if(root==NULL) return;
        
        if(root->val==subRoot->val)
            same_vertex.push_back(root);
        
        find_node(root->left,subRoot,same_vertex);
        find_node(root->right,subRoot,same_vertex);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        vector<TreeNode*> same_vertex;
        find_node(root,subRoot,same_vertex);
            
        // if(temp==NULL) cout<<"NULL";
        // else cout<<temp->val;
        
        // if() return false;
        
        for(auto temp:same_vertex)
            cout<<temp->val<<" ";
        
        for(auto temp:same_vertex)
        {
             if(is_subtree(temp,subRoot))
                 return true;
        }
        
            return false;
        
 }
};