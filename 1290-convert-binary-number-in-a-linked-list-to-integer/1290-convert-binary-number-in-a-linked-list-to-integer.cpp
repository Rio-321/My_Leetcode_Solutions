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
    int getDecimalValue(ListNode* head) {
     
        vector<int> vec;
        
        ListNode* curr = head;
        
        while(curr!=NULL)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        
        int pow = 1;
        int res = 0;
        
        for(int i=vec.size()-1;i>=0;i--)
        {
            
            if(vec[i]==1)
                res += pow;
            
            pow = pow*2;
            
        }
        
        return res;
    }
};