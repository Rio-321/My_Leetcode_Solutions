/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


// MY SOLUTION
// Time - theta(n);
// Space - O(n) or O(width of tree);

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL) return NULL;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        
        while(q.size()>1)
        {
            Node* curr = q.front();
            q.pop();
            
            if(curr==NULL)
            {
                q.push(NULL);
                continue;
                
            }
            
            curr->next = q.front();
            if(curr->left!=NULL)
                q.push(curr->left);
            
            if(curr->right!=NULL)
                q.push(curr->right);
              
        }
        
        return root;
        
        // see solution by sohammehta in comments -https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37503/C%2B%2B-IterativeRecursive
        
    }
};