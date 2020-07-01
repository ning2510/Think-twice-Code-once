class MinStack {
    stack <int> ss;
    stack <int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        ss.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        ss.pop();
        min_stack.pop();
    }
    
    int top() {
        return ss.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */