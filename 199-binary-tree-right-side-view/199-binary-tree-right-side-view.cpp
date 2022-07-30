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
    
    int max_level;
    vector<int> ans;
    
    void func(TreeNode* root, int level)
    {
        if(root==NULL)
            return;
        
        if(level == max_level)
        {
            ans.push_back(root->val);
            max_level++;
        }
        
        func(root->right, level+1);
        func(root->left, level+1);
        
        return;
        
    }
    
    vector<int> rightSideView(TreeNode* root)
    {
        max_level = 0;
        
        func(root, 0);
        
        return ans;
        
    }
    
};


// class Solution {
// public:
    
//     // My Solution
//     vector<int> rightSideView(TreeNode* root) {
        
//         if(root==NULL) return {};
//         vector<int> nodes;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int size = q.size();
//             for(int i=0;i<size;i++)
//             {
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 if(i==size-1)
//                     nodes.push_back(curr->val);
                
//                 if(curr->left!=NULL)
//                     q.push(curr->left);
//                 if(curr->right!=NULL)
//                     q.push(curr->right);
//             }
//         }
        
//         return nodes;
//     }
// };