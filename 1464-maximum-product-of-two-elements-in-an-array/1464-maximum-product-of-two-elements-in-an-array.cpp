class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(nums[0]);
        pq.push(nums[1]);
        
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        int num = pq.top();
        pq.pop();
        return (num-1)*(pq.top()-1);
    }
};