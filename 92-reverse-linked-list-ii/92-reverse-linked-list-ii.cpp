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
                startN = prevN;
                head1 = curr;
            }
            
            if(cnt==right)
            {
                endN = curr->next;
                curr->next = NULL;
                break;
            }
            
            prevN = curr;
            curr = curr->next;
            cnt++;
        }
        
        // cout<<startN->val<<"\n";
        // cout<<endN->val<<"\n";
        
        cout<<"\n\n";
        
        
        curr = head1;
        
        // cout<<curr->val<<"\n";
        
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(curr!=NULL)
        {  
            cout<<curr->val<<" ";
            
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
//         cout<<prev->val<<" ";
        
        
        // startN->next->next = endN;
        head1->next = endN;
        
        if(startN==NULL)
            head = prev;
        else
           startN->next = prev;
        
        return head;
        
    }
};