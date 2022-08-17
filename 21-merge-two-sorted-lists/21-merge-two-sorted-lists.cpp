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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* dummy = new ListNode();
        
        ListNode* tail = dummy;
        
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        while(curr1!= NULL || curr2!= NULL)
        {
            if(curr1 == NULL )
            {
               tail->next = curr2;
                break;
            }
            else if(curr2 == NULL)
            {
                tail->next = curr1;
               break;
            }
           
            if(curr1->val >= curr2->val)
            {
                tail->next = curr2;
                curr2 = curr2->next;
            }
            else
            {
               tail->next = curr1;
                curr1 = curr1->next;
            }
                
            
            tail = tail->next;
                
        }
        
        return dummy->next;
        
    }
};