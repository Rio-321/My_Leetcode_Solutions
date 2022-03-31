class Solution {
    
public:

    void parenthesis(string str,int cnt1,int cnt2,vector<string> &res,int &n)
    {   
        if(cnt1<cnt2) return;
         if(cnt1==n)
         {
             while(cnt2<n)
             {
                 str = str + ')';
                 cnt2++;
             }
             
             res.push_back(str);
             return;
             
         }
        if(cnt1==cnt2) parenthesis(str+'(',cnt1+1,cnt2,res,n);
        
        if(cnt1>cnt2)
        {
            parenthesis(str+'(',cnt1+1,cnt2,res,n);
            parenthesis(str+')',cnt1,cnt2+1,res,n);
            
        }
        
        return;
    }
    
    
    vector<string> generateParenthesis(int n) 
    {
       int cnt1=0,cnt2 =0;
       vector<string> res;
       string str;
        
        parenthesis(str,cnt1,cnt2,res,n);
        return res;
    }

};