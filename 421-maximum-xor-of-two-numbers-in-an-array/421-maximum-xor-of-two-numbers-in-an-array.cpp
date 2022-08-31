class Node{
public:
    Node* zero;
    Node* one;
};

class Solution {
public:
    
    Node* root;
    
    void insert(int n)
    {
        Node* temp = root;
        
        for(int i=31;i>=0;i--)
        {
            int num = ((n >> i) & 1);
            if(num == 0)
            {
                if(temp->zero == NULL)
                    temp->zero = new Node();
                
                temp = temp->zero;
            }
            else
            {
                 if(temp->one == NULL)
                     temp->one = new Node();
                
                temp = temp->one;
            }
        }
    }
    
    int max_Xor(int n)
    {
        Node* temp = root;
        int ans = 0;
        
        for(int i=31;i>=0;i--)
        {
            int num = ((n >> i) & 1);
            
            if(num == 1)
            {
                if(temp->zero != NULL)
                {
                    ans += (1<<i);
                    temp = temp -> zero;
                }
                else
                    temp = temp->one;
            }
            else
            {
                 if(temp->one != NULL)
                 {
                     ans += (1<<i);
                     temp = temp->one;
                 }
                else
                    temp = temp->zero;
            }
        }
        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        root = new Node();
        
        int n = nums.size();
        for(int i=0;i<n;i++)
              insert(nums[i]);
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            ans = max(ans, max_Xor(nums[i]));
            cout << ans << " ";
        }
        
        return ans;
    }
};

