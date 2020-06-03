class MedianFinder {
public:
    priority_queue <int> ss;
    priority_queue <int, vector<int>, greater<int> > pp;

    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        ss.push(num);
        pp.push(ss.top());
        ss.pop();
        if(ss.size() < pp.size()) {
            ss.push(pp.top());
            pp.pop();
        }
        return ;
    }
    
    double findMedian() {
        return ss.size() > pp.size() ? (double)ss.top() : (ss.top() + pp.top()) * 1.0 / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */