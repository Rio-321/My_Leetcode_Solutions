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
     
        stack<ListNode*> st1,st2;
        
        ListNode* curr = l1;
        while(curr)
        {
            st1.push(curr);
            curr = curr->next;
        }
        curr = l2;
        
        while(curr)
        {
            st2.push(curr);
            curr = curr->next;
        }
        
        
        int rem = 0, num = 0, div = 0;
        ListNode* temp = NULL;
        
        while(!st1.empty() && !st2.empty())
        {
            num = st1.top()->val + st2.top()->val + rem;
            div = num%10;

                if(st1.size() > st2.size())
                {
                    temp = st1.top();
                    st1.top()->val = div; 
                    
                }
                else
                {
                    temp = st2.top();
                    st2.top()->val = div;
                    
                }
            
             rem = num/10;
             st1.pop(); st2.pop();
        }
        
        if(st1.empty() && st2.empty())
        {
            if(!rem)
                return temp;
            else
            {
                ListNode* ans = new ListNode(rem);
                ans->next = temp;
                return ans;
            }
        }
        
        while(!st1.empty())
        {
            ListNode* temp = st1.top();
            
            num = st1.top()->val + rem;
            div = num%10;
            
            st1.top()->val = div;
            
            rem = num/10;
            st1.pop();
            
            
            if(st1.size() == 0)
            {
                if(!rem)
                {
                    return temp;
                }
                else
                {
                    ListNode* ans = new ListNode(rem);
                    ans->next = temp;
                    return ans;
                }
            }
            
        }
        
        while(!st2.empty())
        {
            ListNode* temp = st2.top();
            
            num = st2.top()->val + rem;
            div = num%10;
            
            st2.top()->val = div;
            
            rem = num/10;
            st2.pop();
            
            
            if(st2.size() == 0)
            {
                if(!rem)
                {
                    return temp;
                }
                else
                {
                    ListNode* ans = new ListNode(rem);
                    ans->next = temp;
                    return ans;
                }
            }
            
        }
        
        return NULL;
        
    }
};