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
    bool isPalindrome(ListNode* head) {
        
        if(head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        stack<ListNode*> st;
        
        while(fast && fast->next)
        {
            st.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // st.pop();
        
        if(fast!=NULL)
        {
            slow = slow->next;
        }
        
        while(!st.empty())
        {
            if(st.top()->val != slow->val)
                return false;
            else
            {
                st.pop();
                slow = slow->next;
            }
        }
        
        // cout<<slow->val<<" ";
        
        return true;
        
    }
};