class Solution {
public:
    
    // VERY BRUTE FORCE APPROACH
    // MY SOLUTION
    string intToRoman(int n) {
        
    int mult = 1;

    string ans = "";

    stack<int> st;

    map<int,char> mp;
    mp[1] = 'I';
    mp[5] = 'V';
    mp[10] = 'X';
    mp[50] = 'L';
    mp[100] = 'C';
    mp[500] = 'D';
    mp[1000] = 'M';
    mp[5000] = 'S';

    vector<int> vec = {1,5,10,50,100,500,1000,5000};
        
        
    while(n)
    {
        st.push((n%10)*mult);
        mult = mult*10;
        n = n/10;
    }

    mult = mult/10;
        
    while(!st.empty())
    {
        int p = st.top();
        st.pop();
        
        if(p==0)
        {
            mult = mult/10;
            continue;
        }
            

        int l = 0, r = vec.size()-1;
        int res = 0;
        while(l<=r)
        {
            int mid  = (l+r)/2;
            if(vec[mid]==p)
            {
                res = mid;
                break;
            }

            if(vec[mid]>p)
            {
                r = mid-1;
            }
            else
            {
                res = mid;
                l = mid+1;
            }
        }
        

        if(vec[res+1]-p==mult)
        {
            for(int i=0;i<(vec[res+1]-p)/mult;i++)
                ans.push_back(mp[mult]);

            ans.push_back(mp[vec[res+1]]);
        }
        else
        {
            ans.push_back(mp[vec[res]]);
            for(int i=0;i<(p-vec[res])/mult;i++)
                ans.push_back(mp[mult]);
        }

        mult = mult/10;
    }
        
        
        return ans;

    }
};