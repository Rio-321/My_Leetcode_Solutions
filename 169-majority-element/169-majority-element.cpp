class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int vote = 0, majority = -1;
        
        for(int i=0;i<n;i++)
        {
            if(vote == 0)
            {
                vote = 1;
                majority = nums[i];
            }
            else
            {
                if(nums[i] == majority)
                    vote++;
                else
                    vote--;
            }
            
            // cout<<vote<<" ";
        }
        
        // cout<<vote<<" "<<majority<<"\n";
        
        if(vote == 0)
            return -1;
        
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == majority)
                count++;
        }
        
        if(count > n/2)
            return majority;
        else
            return -1;
    }
};




// Boyer-Moore Voting algorithm is used

// Approach 3 - sort the array and return middle element