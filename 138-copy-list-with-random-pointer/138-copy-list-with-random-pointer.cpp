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
        
        if(head == NULL)
           return NULL;
         
        Node* curr = head;
        Node* newHead = NULL;
        Node* prev = NULL;
        
        map<Node*, vector<pair<Node*, Node*>>> mp;
        
        while(curr != NULL)
        {
            Node* temp = new Node(curr->val);
            
            
            if(prev != NULL)
                prev->next = temp;
            
            prev = temp;
            
            if(newHead == NULL)
                newHead = temp;

            
            mp[curr->random].push_back({curr, temp});
            curr = curr->next;
        }
        
        curr = head;
        Node* currNew = newHead;
        
        // cout<<currNew->next->random<<"\n";
        
        while(curr != NULL)
        {
            if(mp.find(curr) != mp.end())
            {
                for(auto x:mp[curr])
                {
                    x.second -> random = currNew;
                }
                 // mp[curr].second -> random = currNew;
            }
            
            curr = curr->next;
            currNew = currNew->next;
        }
        
    
        
        return newHead;
    }
};