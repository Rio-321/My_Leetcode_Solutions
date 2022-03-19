class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.length()==0) return {};
        vector<string> res;
        res.push_back("");
        vector<string> no_list = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        for(auto num: digits)
        {
            int x = num - '0';
            string str = no_list[x];
            vector<string> temp;
            for(auto res_i:res)
            {
                for(auto s:str)
                {
                    temp.push_back(res_i + s);
                }
            }
            
            res.swap(temp);
        }
        
        return res;
    }
};