class MinStack {
public:
  
    // https://leetcode.com/problems/min-stack/discuss/1209254/C%2B%2B-Simple-code-with-one-stack
    stack<pair<int,int>> st;
    
    MinStack() {
        
        
    }
    
    void push(int val) {
        
        if(st.empty())
            st.push({val,val});
        else
        {
            int mini = min(st.top().second, val);
            st.push({val, mini});
        }
       
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        
        int num = st.top().first;
        // st.pop();
        return num;
        
    }
    
    int getMin() {
        
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */