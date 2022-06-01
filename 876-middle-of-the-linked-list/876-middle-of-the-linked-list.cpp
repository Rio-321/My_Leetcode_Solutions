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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL)
        {   
            if(fast->next==NULL)
                break;
            
            if(fast->next->next==NULL)
            {
                slow = slow->next;
                break;
            }
            
            fast = fast->next->next;
            slow = slow->next;
            
            
        }
        
        
        return slow;
        
        
    }
};