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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        stack<TreeNode*> st;

        q.push(root);
        bool reverse = false;
        
        while(!q.empty())
        {   
            vector<int> temp;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(reverse)
                    st.push(curr);
                else
                {
                    temp.push_back(curr->val);
                }
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                
            }
            
            while(!st.empty())
            {
                temp.push_back(st.top()->val);
                st.pop();
            }
            
            reverse = !reverse;
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};