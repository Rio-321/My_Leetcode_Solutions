class Solution {
public:
    vector<string> ans;
    
    void value(string num, int target)
    {
        num = num + "+";
        long long res = 0;
        long long prev = 0;
        char sign = '+';
        long long curr = 0;
        
        
        for(auto c:num)
        {  
             if(c==' ') continue;
          
            if(isdigit(c))
            {
                curr = curr*10 + (c-'0');
            }
            else
            {
                if(sign=='*')
                {
                    prev = prev*curr;
                    curr=0;
                    sign = c;
                }
                else 
                {
                    if(sign=='-')
                    {
                       res =  res + prev;
                        prev = -curr;
                    } 
                    else if(sign=='+')
                    {
                        res = res + prev;
                        prev = curr;
                    }

                    curr = 0;
                    sign = c;
                }
            }
        }
        
        res = res + prev;
        
        num.pop_back();
        
        
        // return res;        
        if(res==target)
            ans.push_back(num);
    }
    
    
    void solve(const string &path, string num, int index, int target, long long resSoFar, long long prevNum)
    {

        if(index==num.length())
        {
            if(resSoFar==target)
                ans.push_back(path);
                
            return;
        }
        
        string temp;
        long No = 0;
        
        for(int i=index;i<num.length();i++)
        {    
            if(i>index && num[index]=='0') break;
            
            temp += num[i];
            
            No = No*10 + num[i]-'0';
            
             if(index==0)
                {
                   solve(path + temp, num, i + 1, target,No,No) ;
                }
            else
            {
                solve(path + "+" + temp,num,i+1,target,resSoFar+No, No);
            
                solve(path + "-" + temp, num, i+1, target, resSoFar-No, -No);
            
                solve(path + "*" + temp, num, i+1, target,resSoFar-prevNum + prevNum*No, prevNum*No);
                
            }
   
        }     
        
    }
    
    
    vector<string> addOperators(string num, int target) {
        
        
        if(num.length()==1) return {};
        
        solve("",num,0,target,0,0);
        
        
        return ans;
    }
};