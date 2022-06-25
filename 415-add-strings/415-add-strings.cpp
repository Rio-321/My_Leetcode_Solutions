class Solution {
public:
    string addStrings(string str1, string str2) {
       string res = "";

    int rem = 0;
    int curr = 0;
    int len1 = str1.length();
    int len2 = str2.length();

    int max_len = max(len1, len2);

    str1 = string( max_len- len1, '0') + str1;
    str2 = string( max_len- len2, '0') + str2;

    // cout<<str1<<br;
    // cout<<str2<<br;


    for(int i=max_len-1;i>=0;i--)
    {

        curr = (str1[i] - '0') + (str2[i]-'0') + rem;
        rem = curr/10;
        curr = curr % 10;
        res = char(curr + '0') + res;
    }

    // cout<<rem<<br;

    if(rem)
        res = char(rem + '0') + res;

    // cout<<res<<br;

    return res;
        // https://leetcode.com/problems/add-strings/discuss/90453/C%2B%2B_Accepted_13ms

    }
};