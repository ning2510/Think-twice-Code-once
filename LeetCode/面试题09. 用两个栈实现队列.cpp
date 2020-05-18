class CQueue {
public:
    stack <int> ss;
    stack <int> pp;

    CQueue() {

    }
    
    void appendTail(int value) {
        while(!ss.empty()) {
            pp.push(ss.top());
            ss.pop();
        }
        ss.push(value);
        while(!pp.empty()) {
            ss.push(pp.top());
            pp.pop();
        }
    }
    
    int deleteHead() {
        if(ss.empty()) return -1;
        int ans = ss.top();
        ss.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */