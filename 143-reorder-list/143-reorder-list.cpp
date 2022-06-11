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
    void reorderList(ListNode* head) {
        
        if(head->next==NULL || head->next->next==NULL)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        if(fast==NULL)
        {
           curr = slow;
           prev->next = NULL; 
        } 
        else
        {
           curr = slow->next;
           slow->next = NULL; 
        }
        
        
        stack<ListNode*> st;
        while(curr!=NULL)
        {
            st.push(curr);
            curr = curr->next;
        }
        
        
        ListNode* left = head;
        
        while(!st.empty())
        {
           ListNode* right = st.top();
           st.pop();
           ListNode* temp = left->next;
           left->next = right;
           right->next = temp;
           left = temp;
        }
        
    }
};