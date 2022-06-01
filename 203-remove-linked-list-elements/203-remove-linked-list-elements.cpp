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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        
        if(head->next==NULL)
        {
            if(head->val==val)
                return NULL;
            else
                return head;
        }
        
        
        
        ListNode* curr = head;
        while(curr->next!=NULL)
        {
           if(curr->next->val==val)
               curr->next = curr->next->next;
            else
                curr = curr->next;
        } 
        
        if(head->next==NULL)
        {
            if(head->val==val)
                return NULL;
            else
                return head;
        }
        
        if(head->val==val)
            head = head->next;
        
        
        
        
              
        return head;
        
    }
};