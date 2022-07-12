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
   
    unsigned long long widthOfBinaryTree(TreeNode* root) {
       
        if(!root)
            return 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        unsigned long long ans = 1;
        
        while(!q.empty())
        {
            unsigned long long count = q.size();
            // int nullCount = 0;
            
            unsigned long long first = -1;
            unsigned long long last = -1;
            
            for(unsigned long long i=0;i<count;i++)
            {
                pair<TreeNode*, unsigned long long> curr = q.front();
                q.pop();
                
                if(i == 0)
                    first = curr.second;
                
                if(i == count-1)
                    last = curr.second;
                
                
                if(curr.first->left)
                    q.push({curr.first->left, curr.second*2});
                
                if(curr.first->right)
                    q.push({curr.first->right, curr.second*2 + 1});
                  
            }
            
            // cout<<first<<" "<<last<<"\n";
            
            
            ans = max(ans, last-first+1);
        }
        
        
        return ans;
        
        
    }
};