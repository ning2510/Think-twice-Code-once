class MaxQueue {
public:
    int l1, r1, l2, r2;
    int ss[10005], maxn[10005];

    MaxQueue() {
        l1 = l2 = 0;
        r1 = r2 = -1;
    }
    
    int max_value() {
        if(l2 > r2) return -1;
        return maxn[l2];
    }
    
    void push_back(int value) {
        ss[++r1] = value;
        while(l2 <= r2 && value > maxn[r2]) {
            r2--;
        }
        maxn[++r2] = value;
        return ;
    }
    
    int pop_front() {
        if(l1 > r1) return -1;
        if(ss[l1] == maxn[l2]) l2++;
        return ss[l1++];
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */