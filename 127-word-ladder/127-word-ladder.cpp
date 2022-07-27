class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        st.insert(beginWord);
        
        // for(auto x:st)
        //     cout<<x<<" ";
        
        int count = 1;
        queue<string> q;
        
        q.push(beginWord);
        
        
        while(!q.empty())
        {
            int siz = q.size();
            
            for(int k=0;k<siz;k++)
            {
                string str = q.front();
                q.pop();

                cout<<str<<" ";
                st.erase(str);

                for(int i=0;i<str.size();i++)
                {
                    char c = str[i];
                    for(int j=0;j<26;j++)
                    {
                        char ch = char(j+'a');
                        
                        
                        if(str[i] == ch)
                            continue;
                        
                        str[i] = ch;
                        
                        // cout<<str<<" ";
                        
                        

                        if(st.count(str))
                        {   
                            if(str == endWord)
                            {
                                // cout<<"YES\n";
                                return count+1;
                            }
                            q.push(str);
                        }

                    }
                    
                    str[i] = c;
                }
                
            }
            
            count++;
              
        }
        
        return 0;
        
    }
};