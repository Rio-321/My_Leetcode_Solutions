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
    
    bool is_identical(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        
        if(root->val != subRoot->val) return false;
        
        return (is_identical(root->left, subRoot->left) && is_identical(root->right,subRoot->right));
    }
    
//     void check_Nodes(TreeNode* root,int d, int curr_d, TreeNode* subRoot)
//     {
//         if(root==NULL) return;
        
//         if(curr_d==d)
//         {
//             if(root->val==subRoot->val)
//                 nodes.push_back(root);
            
//             return;
//         }
//         else
//         {
//             check_Nodes(root->left,d,curr_d-1,subRoot);
//             check_Nodes(root->right,d,curr_d-1,subRoot);
//         }
            
        
//     }
    
    int MaxDepth(TreeNode* root, int d)
    {
        if(root==NULL) return 0;
        
        int dept = max(MaxDepth(root->left,d),MaxDepth(root->right,d)) + 1;
        
        
        if(dept==d)
            nodes.push_back(root);
        
        return dept;
    }
    
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        

    int sub_depth = MaxDepth(subRoot, -1);
    int depth = MaxDepth(root, sub_depth);
    
    // cout<<d<<" "<<depth<<"\n";
        
    // check_Nodes(root,d,depth,subRoot);
    // cout<<nodes.size()<<"\n";
        
    // cout<<nodes[0]->val<<"\n";
        
    // cout<<depth;

    for(auto Node:nodes)
    {
        if(is_identical(Node,subRoot))
            return true;
    }
        
    return false;
 }
};




// https://leetcode.com/problems/subtree-of-another-tree/discuss/102734/19ms-C%2B%2B-solution-beats-99.9