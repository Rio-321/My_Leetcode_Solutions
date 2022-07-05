/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //Basic Approach
        if(head == NULL)
           return NULL;
         
        Node* curr = head;
        
        map<Node*, Node*> mp;
        
        while(curr != NULL)
        {
            Node* temp = new Node(curr->val);

            mp[curr] = temp;
            curr = curr->next;
        }
        
        curr = head;
        
        
        while(curr != NULL)
        {
            
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            
            curr = curr->next;
        }
        
    
        
        return mp[head];
    }
};