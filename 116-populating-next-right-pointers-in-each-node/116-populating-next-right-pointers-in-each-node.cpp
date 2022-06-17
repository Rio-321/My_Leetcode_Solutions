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

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL) return NULL;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        Node* prev = NULL;
        
        while(q.size()>1)
        {
            Node* curr = q.front();
            q.pop();
            
            if(curr==NULL)
            {
                prev = curr;
                q.push(NULL);
                continue;
                
            }
            // cout<<curr->val<<" ";
            
            if(prev!=NULL)
            {
                prev->next = curr;
            }
            
            if(curr->left!=NULL)
                q.push(curr->left);
            
            if(curr->right!=NULL)
                q.push(curr->right);
            
            prev = curr;
              
        }
        
        
        return root;
        
    }
};