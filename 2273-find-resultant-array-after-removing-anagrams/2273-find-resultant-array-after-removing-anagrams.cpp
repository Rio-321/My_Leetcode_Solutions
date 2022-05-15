class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       
        for(int i=1;i<words.size();i++)
        {
            string curr = words[i];
            string prev = words[i-1];
            sort(curr.begin(),curr.end());
            sort(prev.begin(),prev.end());
            
            if(curr==prev)
            {
                words.erase(words.begin()+i);
                i--;
            }
        }
        
        return words;
        
        
    }
};