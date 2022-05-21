class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        priority_queue<int> pq(nums.begin(), nums.end());
        
        int pdt = 1;
        pdt *= pq.top()-1;
        pq.pop();
        pdt *= pq.top()-1;
        
        return pdt;
    }
};