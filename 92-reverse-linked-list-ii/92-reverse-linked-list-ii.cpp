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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head->next==NULL || left==right)
            return head;
        
        ListNode* prevN = NULL;
        ListNode* nextN = NULL;
        ListNode* headN = NULL;
        ListNode* startN = NULL;
        ListNode* endN = NULL;
        ListNode* curr = head;
        ListNode* head1 = NULL;
        int cnt = 1;
        
        while(curr!=NULL)
        {
            if(cnt==left)
            {
                head1 = curr;
                break;
            }
            
            prevN = curr;
            curr = curr->next;
            cnt++;
        }
        
        ListNode* temp = NULL;
        ListNode* lastNode = NULL;
        
        
        while(curr!=NULL)
        {
            temp = curr->next;
            curr->next = lastNode;
            lastNode = curr;
            curr = temp;
            
            cnt++;
            if(cnt>right)
                break;
        }
        
        if(prevN!=NULL)
            prevN->next = lastNode;
        else
            head = lastNode;
        
        
        head1->next = temp;
        

        
        return head;
        
    }
};