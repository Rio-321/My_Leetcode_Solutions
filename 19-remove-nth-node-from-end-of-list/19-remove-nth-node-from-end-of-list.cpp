/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head->next)
            return NULL;
        
        queue<ListNode*> q;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr)
        {
            q.push(curr);
            
            if(q.size() > n)
            {
                prev = q.front();
                q.pop();
            }
                
            
            curr = curr->next;
        }
        
        // ListNode* temp1 = q.front();
        
        
        if(!prev)
        {
            q.pop();
            
            if(q.empty())
                return NULL;
            else
                return q.front();
        }
            
        q.pop();
        prev->next = (!q.empty()) ? q.front() : NULL;
        // q.pop();
        
        // temp1->next = temp2->next;
        
        return head;
        
    }
};