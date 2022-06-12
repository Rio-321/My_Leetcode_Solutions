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
    vector<int> nodes;
    int index=0;
    void Inorder(TreeNode* root, int flag, int &index)
    {
        if(root==NULL) return;
        
        Inorder(root->left,flag,index);
       
        if(flag==1)
        {
            // if(root->val!=nodes[index])
            // {
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
        
//         TreeNode* one = NULL;
      
//         int i=0;
        
//         for(i=0;i<nodes.size()-1;i++)
//         {
//             if(nodes[i]->val > nodes[i+1]->val)
//             {
//                 one = nodes[i];
//                 break;
//             }
//         }
        
//         // cout<<one->val<<"\n";
//         i = nodes.size()-1;
//         for(;i>=1;i--)
//         {
//             if(nodes[i-1]->val > nodes[i]->val)
//             {
//                 break;
//             }
//         }
//         // cout<<nodes[i]->val;
        
//         int temp = one->val;
//         one->val = nodes[i]->val;
//         nodes[i]->val = temp;
        
        
        
        // cout<<"\n\n"<<temp;
        
        
           
    }
};