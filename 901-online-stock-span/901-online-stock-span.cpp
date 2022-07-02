class StockSpanner {
public:
    
        vector<int> arr;
        int i = 0;
        stack<int> st;
    
    StockSpanner() {
         arr.resize(10001);
    }
    
    int next(int price) {
        
        while(!st.empty() && arr[st.top()] <= price)
              st.pop();
        
        int ans;
        if(st.empty())
        {
            ans = i+1;
        }
        else
        {
            ans = i - st.top();
        }
        
        arr[i] = price;
        st.push(i);
        i++;
        
        return ans;
         
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */