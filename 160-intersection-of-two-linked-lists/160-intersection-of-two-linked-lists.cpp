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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        int len1 = -1,len2 = -1;
        
        int cnt = 0;
        
        while(curr1!=curr2)
        {
            if(curr1==NULL)
            {
               curr1 = headB; 
               len1 = cnt;
            } 
            else
                curr1 = curr1->next;
            
            if(curr2==NULL)
            {
                len2 = cnt;
                curr2 = headA;
            }   
            else
                curr2 = curr2->next;
            
            cnt++;
            
        }
        
        return curr1;
        
        
        
        
        
        
        // ******************************************************************
        //MY APROACH
        
//         set<ListNode*> st;
        
//         ListNode* curr1 = headA;
//         ListNode* curr2 = headB;
        
//         while(curr1!=NULL || curr2!=NULL)
//         {
//             if(curr1==curr2)
//                 return curr1;
//             if(st.find(curr1)!=st.end())
//                 return curr1;
//             if(st.find(curr2)!=st.end())
//                 return curr2;
            
            
//             // cout<<curr1->val<<" "<<curr2->val<<"\n";
            
//             if(curr1!=NULL)
//             {
//                 st.insert(curr1);
//                 curr1 = curr1->next;  
//             }
                
            
//             if(curr2!=NULL)
//             {
//                 st.insert(curr2);
//                 curr2 = curr2->next;
//             }
                   
//         }
        
//         return NULL;
    }
};