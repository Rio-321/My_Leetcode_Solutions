/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> ans;
    
    int depthOf(TreeNode* root, TreeNode* target, int k)
    {
        if(root==NULL) return -1;
        if(root->val==target->val) 
        {
            printNodes(root, k);
            return 0;
        }
        
        
        int dl = depthOf(root->left,target,k);
        if(dl!=-1) 
        {
            if(k==dl+1)
                ans.push_back(root->val);
            printNodes(root->right, k-dl-2);
            return dl+1;
        }
        
        
        int dr = depthOf(root->right,target,k);
        if(dr!=-1)
        {  
            if(k==dr+1)
                ans.push_back(root->val);
            
            printNodes(root->left, k-dr-2);
            return dr+1;
        }
        
        
        return dl;
        
    }
    
    void printNodes(TreeNode* root,int depth)
    {
        if(depth<0) return;
        if(root==NULL) return;
        
        if(depth==0)
            ans.push_back(root->val);
        
        printNodes(root->left,depth-1);
        printNodes(root->right,depth-1);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        
        int depth = depthOf(root,target,k);
        
        // cout<<depth<<"\n";
        
        return ans;
        
    }
};



// if you get target node then --> printNodes(root,k)
    
    
// if we get the element in the left do not need to traverse to right;
