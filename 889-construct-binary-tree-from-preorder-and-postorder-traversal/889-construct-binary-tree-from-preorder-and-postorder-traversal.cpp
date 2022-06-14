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
    
    TreeNode* func(int i,int left, int right,vector<int> &preorder, vector<int> &postorder)
    {
        // int i=0;
        
        if(i>=preorder.size() || left>right) return NULL;
        
        
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        
        
        int ind1;
        if(i>=preorder.size())
        {
            root->left = NULL;
        }
        else
        {   
            for(int k=left;k<=right;k++)
            {
                if(postorder[k] == preorder[i])
                {
                    root->left = func(i,left,k,preorder,postorder);
                    ind1 = k;
                    break;
                }
            }
        }
        
        
        if(right==0)
        {
            root->right = NULL;
        }
        else
        {
            for(int k=i;k<preorder.size();k++)
            {
                if(preorder[k]==postorder[right-1])
                {
                   root->right = func(k,ind1+1,right-1,preorder,postorder); 
                }
            }
        }
        return root;   
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        
        int n = preorder.size();
        return func(0,0,n-1,preorder,postorder);
        
       
        
    }
};