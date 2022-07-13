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
    ListNode* oddEvenList(ListNode* head) {
        
          ListNode* even = new ListNode(-1);
          ListNode* odd = new ListNode(-1);
        
          ListNode* prev_even = even;
          ListNode* prev_odd = odd;
        
          ListNode* curr = head;
        
          int flag = 1;
        
          while(curr)
          {
              if(flag)
              {
                  prev_even->next = curr;
                  prev_even = curr; 
              }
              else
              {
                  prev_odd->next = curr;
                  prev_odd = curr;
              }
              
              flag = (flag ^ 1);
              curr = curr->next;
          }
        
         prev_even->next = odd->next;
         prev_odd->next = NULL;
        
        return even->next;
    }
};