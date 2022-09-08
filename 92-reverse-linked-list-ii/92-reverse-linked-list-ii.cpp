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
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* it = dummy;
        ListNode*  prevIt = NULL;
        
        for(int i=0;i<left;i++)
        {
            prevIt = it;
            it = it->next;
        }
        
        ListNode* itR = it;
        ListNode* prevR = prevIt;
        
        for(int i=left;i<=right;i++)
        {
            ListNode* forward = itR->next;
            itR->next = prevR;
            
            prevR = itR;
            itR = forward;
        }
        
        prevIt->next = prevR;
        it->next = itR;
        
        return dummy->next;
        
//         ListNode* prevN = NULL;
//         ListNode* curr = head;
//         ListNode* head1 = NULL;
//         ListNode* temp = NULL;
//         ListNode* lastNode = NULL;
//         int cnt = 1;
        
//         while(curr!=NULL)
//         {
//             if(cnt==left)
//             {
//                 head1 = curr;
//                 break;
//             }
            
//             prevN = curr;
//             curr = curr->next;
//             cnt++;
//         }
        
        
//         while(curr!=NULL && cnt<=right)
//         {
//             temp = curr->next;
//             curr->next = lastNode;
//             lastNode = curr;
//             curr = temp;
            
//             cnt++;
//         }
        
//         if(prevN!=NULL)
//             prevN->next = lastNode;
//         else
//             head = lastNode;
        
        
//         head1->next = temp;
        

        
//         return head;
        
    }
};