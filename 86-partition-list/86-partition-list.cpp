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
    ListNode* partition(ListNode* head, int x) {
        
       ListNode* curr = head;
       ListNode* newhead = NULL;
       
        ListNode* small = NULL;
        ListNode* big = NULL;
        ListNode* mid = NULL;
        
        
        while(curr!=NULL)
        {
            if(curr->val < x)
            {
                if(small != NULL)
                {
                    small->next = curr;
                    small = curr;
                }
                else
                {
                    small = curr;
                    newhead = curr;
                }
                    
            }
            else
            {
                if(big!=NULL)
                {
                    big->next = curr;
                    big = curr;
                    
                }
                else
                {
                    big = curr;
                    mid = curr;
                }
            }
            
            curr = curr->next;
        }
        
        if(small!=NULL)
        small->next = mid;
        
        if(big!=NULL)
        big->next = NULL;
        
        // while(small!=NULL)
        // {
        //     cout<<small->val<<" ";
        //     small = small->next;
        // }
        
        if(newhead != NULL)
        return newhead;
        else
            return head;
    }
};