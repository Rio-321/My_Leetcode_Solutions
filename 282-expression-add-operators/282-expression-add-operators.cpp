class Solution {
public:
    vector<string> ans;
    

    
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
    
    // best solution - https://leetcode.com/problems/expression-add-operators/discuss/572099/C%2B%2BJavaPython-Backtracking-and-Evaluate-on-the-fly-Clean-and-Concise
};