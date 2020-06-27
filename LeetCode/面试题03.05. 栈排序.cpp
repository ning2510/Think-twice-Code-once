class SortedStack {
public:
    stack <int> ss, pp;

    SortedStack() {

    }
    
    void push(int val) {
        while(!ss.empty() && ss.top() < val) {
            pp.push(ss.top());
            ss.pop();
        }
        ss.push(val);
        while(!pp.empty()) {
            ss.push(pp.top());
            pp.pop();
        }
        return ;
    }
    
    void pop() {
        if(!ss.empty()) ss.pop();
    }
    
    int peek() {
        if(!ss.empty()) return ss.top();
        return -1;
    }
    
    bool isEmpty() {
        return ss.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */