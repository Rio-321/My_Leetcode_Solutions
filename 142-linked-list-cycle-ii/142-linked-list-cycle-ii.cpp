/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL)
            return head;
        
        // cout << head->next->next->next->next->val<<"\n";
        
        unordered_set<ListNode*> st;
        ListNode* curr = head;
        
        while(st.find(curr) == st.end())
         {  
            st.insert(curr);
        
            curr = curr->next;
            
            if(curr == NULL)
                return NULL;
        }
        
        return curr;
        
        
    }
};