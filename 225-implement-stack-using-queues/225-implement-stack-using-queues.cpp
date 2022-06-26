class MyStack {
public:
    
    // using one queues
    queue<int> q1;
    int top_elem;
    MyStack() {
        
        
    }
    
    void push(int x) {
        top_elem = x;
        q1.push(x);   
    }
    
    int pop() {
         
        int n = q1.size();
        n--;
        
        while(n--)
        {
            int curr = q1.front();
            q1.pop();
            
            q1.push(curr);
            
            if(n == 0)
                top_elem = curr;
        }
        
        int last = q1.front();
        q1.pop();
        return last;
    }
    
    int top() {
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