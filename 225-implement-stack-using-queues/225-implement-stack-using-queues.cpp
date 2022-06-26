class MyStack {
public:
    
    // using one queues My Approach
    
    // https://leetcode.com/problems/implement-stack-using-queues/discuss/2088290/With-Explanation-comments%3A-C%2B%2B-CPP-Time%3A-7-ms-(9.46)-Space%3A-6.9-MB-(55.40)
    queue<int> q1;
    int top_elem;
    MyStack() {
        
        
    }
    
    void push(int x) {
        top_elem = x;
        int size = q1.size();
        q1.push(x);   
        
        while(size--)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
       int last = q1.front();
       q1.pop();
        return last;
    }
    
    int top() {
        int top_elem = q1.front();
        return top_elem;
    }
    
    bool empty() {
        
        if(q1.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */