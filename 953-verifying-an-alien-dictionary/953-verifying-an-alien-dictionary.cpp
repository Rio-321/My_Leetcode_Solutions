class Solution {
public:
    bool lexiOrder(string first, string second, int alphaOrder[])
    {
        int n = first.length();
        int m = second.length();
        
        
        // if(n>m) return false;
        
        for(int i=0;i<n;i++)
        {    
            if(i==m) return false;
            int x = alphaOrder[first[i]-'a'];
            int y = alphaOrder[second[i]-'a'];
            
            if(x>y) return false;
            if(x<y) return true;
        }
        
        return true;
        
    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        int alphaOrder[26];
        for(int i=0;i<order.length();i++)
        {
            alphaOrder[order[i]-'a'] = i;     
        }
        
        for(int i=0;i<order.length();i++)
        {
            cout<<alphaOrder[i]<<" ";
        }
        
        int n = words.size();
        for(int i=0;i<n-1;i++)
        {
            string first = words[i];
            string second = words[i+1];
            
            if(lexiOrder(first, second,alphaOrder)==false)
                return false;   
        }
        
        return true;
    }
};