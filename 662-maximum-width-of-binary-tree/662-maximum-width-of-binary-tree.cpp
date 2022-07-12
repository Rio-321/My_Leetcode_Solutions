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
   
     long long widthOfBinaryTree(TreeNode* root) {
       
        if(!root)
            return 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
         long long ans = 1;
        
        while(!q.empty())
        {
             long long count = q.size();
            // int nullCount = 0;
            
             long long first = -1;
             long long last = -1;
            
            long long mini = -1;
            for( long long i=0;i<count;i++)
            {
                pair<TreeNode*,  long long> curr = q.front();
                q.pop();
                
                if(i == 0)
                {
                    mini = curr.second;
                    first = curr.second;
                }
                    
                
                if(i == count-1)
                    last = curr.second;
                
                
                if(curr.first->left)
                    q.push({curr.first->left, (curr.second-mini)*2});
                
                if(curr.first->right)
                    q.push({curr.first->right, (curr.second-mini)*2 + 1});
                  
            }
            
            // cout<<first<<" "<<last<<"\n";
            
            
            ans = max(ans, last-first+1);
        }
        
        
        return ans;
        
        
    }
};