class MinStack {    //与LeetCode 155相同
public:
    /** initialize your data structure here. */
    stack <int> ss;
    stack <int> minx;

    MinStack() {

    }
    
    void push(int x) {
        ss.push(x);
        if(minx.empty()) {
            minx.push(x);
        }
        else {
            if(x <= minx.top()) minx.push(x);
        }
    }
    
    void pop() {
        int x = ss.top();
        ss.pop();
        if(x == minx.top()) minx.pop();
    }
    
    int top() {
        return ss.top();
    }
    
    int min() {
        return minx.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */