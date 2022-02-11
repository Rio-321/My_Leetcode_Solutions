/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool Find_Path(TreeNode* root,vector<TreeNode*> &path, TreeNode* n)
{
    if(root==NULL)
        return false;
    
    path.push_back(root);
    
    if(root->val==n->val)
        return true;
    
    
   if(!Find_Path(root->left,path,n) &&  !Find_Path(root->right,path,n))
   {
       path.pop_back();
       return false;
   }
    else
        return true;
}


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL)
            return NULL;
        
        vector<TreeNode*> Path1, Path2;
        
        Find_Path(root,Path1,p);
        Find_Path(root,Path2,q);
        
//         for(int i=0;i<Path1.size();i++)
//             cout<<Path1[i]->val<<" ";
        
//         cout<<"\n";
        
//         for(int i=0;i<Path2.size();i++)
//             cout<<Path2[i]->val<<" ";
        
//         cout<<"\n";
        
        // Path1.push_back(NULL);
        // Path2.push_back(NULL);
        int i=0;
        for(i=0;i<Path1.size() && i<Path2.size();i++)
        {
            if(Path1[i]!=Path2[i])
                break;
                
        }
        
        return Path1[i-1];
        
        // return NULL;
        
    }
};