class Solution {
public:
    string reorderSpaces(string text) {
        
        queue<string> q;
        
        int i=0;
        int cnt = 0;
        while(i<text.length())
        {
            if(text[i]!=' ')
            {
                string temp = "";
                while(i<text.length() && text[i]!=' ')
                {
                    temp += text[i];
                    i++;
                }
                
                q.push(temp);
            }
            else
            {
                cnt++;
                i++;
            }     
        }
        
        
        // cout<<cnt;
        int spaces = 0;
        int rem = cnt;
        
        if(q.size()>1)
        {
        spaces = cnt/(q.size()-1);
        rem = cnt%(q.size()-1);
        }

        
        string space_string = "";
        string last_string = "";
        int k =1;
        while(k<=spaces)
        {
            space_string += " ";
            k++;
        }
        
        k = 1;
        while(k<=rem)
        {
           last_string += " ";
            k++;
        }
        
        string res = q.front();
        q.pop();
        while(!q.empty())
        {
            res = res + space_string + q.front();
            q.pop();
        }
        
        res += last_string;
        
        
        
        return res;
        
        
    }
};