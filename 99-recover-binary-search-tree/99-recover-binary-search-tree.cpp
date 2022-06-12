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
    vector<TreeNode*> nodes;
    void Inorder(TreeNode* root)
    {
        if(root==NULL) return;
        
        Inorder(root->left);
        nodes.push_back(root);
        Inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        
        Inorder(root);
        
        TreeNode* one = NULL;
        
        // for(auto x:nodes)
        //     cout<<x->val<<" ";
        
        // cout<<"\n";
        
        int i=0;
        
        for(i=0;i<nodes.size()-1;i++)
        {
            if(nodes[i]->val > nodes[i+1]->val)
            {
                one = nodes[i];
                break;
            }
        }
        i++;
        
        // cout<<one->val<<"\n";
        i = nodes.size()-1;
        for(;i>=1;i--)
        {
            if(nodes[i-1]->val > nodes[i]->val)
            {
                break;
            }
        }
        // cout<<nodes[i]->val;
        
        int temp = one->val;
        one->val = nodes[i]->val;
        nodes[i]->val = temp;
        
        
        
        // cout<<"\n\n"<<temp;
        
        
           
    }
};