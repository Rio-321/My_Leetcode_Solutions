class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> suffix(n);
        for(int i=n-1;i>=0;i--)
            suffix[i] = ((i<n-1) ? suffix[i+1] : 0) + arr[i];
        
        for(auto x:suffix)
            cout<<x<<" ";
        
        unordered_set<int> St;
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum = sum + arr[i];
            if(sum%2==0 && St.find(sum/2)!=St.end() && i<n-1 && suffix[i+1]==sum/2)
                return true;
            St.insert(sum);
        }
        
        return false;
            
        
    }
};