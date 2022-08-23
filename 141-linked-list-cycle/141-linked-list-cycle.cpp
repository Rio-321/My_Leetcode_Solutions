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
    bool hasCycle(ListNode *head) {
        
        ListNode* curr = head;
        unordered_set<ListNode*> st;
        // st.insert(head);
        
        while(st.find(curr) == st.end())
        {
            if(curr == NULL)
                return false;
            
            st.insert(curr);
            curr = curr->next;
        }
        
        return true;
        
    }
};