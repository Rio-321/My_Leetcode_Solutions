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
        
        ListNode* curr = head;
        int n = 0;
        while(curr!=NULL)
        {
            n++;
            curr = curr->next;
        }
        
        n = n/2 + 1;
        curr = head;
        // cout<<n<<"\n";
        n--;
        
        while(n--)
        {
            curr = curr->next;
        }
        
        
        
        return curr;
        
        
    }
};