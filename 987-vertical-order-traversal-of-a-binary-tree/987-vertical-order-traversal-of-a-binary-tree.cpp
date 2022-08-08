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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(!root) return {{}};
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        
        while(!q.empty())
        {
            auto curr = q.front();
            TreeNode* node = curr.first;
            int vert = curr.second.first;
            int level = curr.second.second;
            
            q.pop();
            mp[vert][level].insert(node->val);
            
            if(node->left)
                q.push({node->left, {vert-1, level+1}});
            
            if(node->right)
                q.push({node->right, {vert+1, level+1}});
            
            
        }
        
        vector<vector<int>> ans;
        
        for(auto &x:mp)
        {
            vector<int> temp;
            
            for(auto &y : x.second)
            {
                for(auto &z: y.second)
                {
                    temp.push_back(z);
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
        
    }
};