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
    
    int func(TreeNode* root, int &camera)
    {
        if(root == NULL) return 1;
        
        int leftCam = func(root->left, camera);
        int rightCam = func(root->right, camera);
        

         if(leftCam == -1 || rightCam == -1)
        {
            camera++;
            return 0;
        }
        else if(leftCam == 0 || rightCam == 0)
            return 1;
        else if(leftCam == 1 && rightCam == 1) 
            return -1;
        
        return 1;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        
        int camera = 0;
        if(func(root, camera) == -1) camera++;
        
        return camera;
        // i need cameras --> -1;
        // i have cameras --> 0;
        // i am covered --> 1
    }
};