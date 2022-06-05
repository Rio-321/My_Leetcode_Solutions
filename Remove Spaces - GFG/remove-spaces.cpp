// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string modify (string s)
    {
        int i=0;
        string res = "";
        while(i<s.length())
        {
            if(s[i]!=' ')
            {
                while(i<s.length() && s[i]!=' ')
                {
                    res = res + s[i];
                    i++;
                }
            }
            else
            i++;
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends