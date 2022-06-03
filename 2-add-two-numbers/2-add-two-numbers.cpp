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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* curr1 = l1;
        ListNode* prev1 = NULL;
        ListNode* curr2 = l2;
        ListNode* prev2 = NULL;
        int rem = 0;
        int quot = 0;
        int sum = 0;
        
        while(curr1!=NULL && curr2!=NULL)
        {
            sum = curr1->val + curr2->val + rem;
            rem = sum/10;
            quot = sum%10;
            curr2->val = quot;
            
            prev1 = curr1;
            prev2 = curr2;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        if(curr1==NULL)
        {  
            cout<<"SECOND";
            while(curr2!=NULL)
            {
                sum = curr2->val + rem;
                rem = sum/10;
                quot = sum%10;
                curr2->val = quot;
                prev2 = curr2;
                curr2 = curr2->next;
            }
            
            if(rem==1)
                prev2->next = new ListNode(1);
        }
        else if(curr2==NULL)
        {    
             cout<<"FIRST";
             prev2->next = curr1;
             while(curr1!=NULL)
             {  
                 sum = curr1->val + rem;
                 rem = sum/10;
                 quot = sum%10;
                 curr1->val = quot;
                 prev1 = curr1;
                 curr1 = curr1->next;
             }
            
            if(rem==1)
                prev1->next = new ListNode(1);
        }

            
        
        
        
        return l2;
    }
    
    
};