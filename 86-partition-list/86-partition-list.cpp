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
    ListNode* partition(ListNode* head, int x) {
        
       ListNode* curr = head;
       ListNode* newhead = NULL;
       
        ListNode* small = NULL;
        ListNode* big = NULL;
        ListNode* mid = NULL;
        
        ListNode* smalldummy = new ListNode(-1);
        ListNode* bigdummy  = new ListNode(-1);
        
        small = smalldummy;
        big = bigdummy;
        
        while(curr!=NULL)
        {
            if(curr->val < x)
            {
                small->next = curr;
                small = curr;
            }
            else
            {
                big->next = curr;
                big = curr;
            }
            
            curr = curr->next;
        }
        
        
        small->next = bigdummy->next;
        big->next = NULL;
        
        return smalldummy->next;
        
        
       
    }
};