class MyCircularDeque {
public:
    int l, r, c;
    vector <int> ss;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        l = 1001;
        r = 1000;
        c = k;
        ss.resize(2005, 0);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(r - l + 1 >= c) return false;
        ss[--l] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(r - l + 1 >= c) return false;
        ss[++r] = value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(l > r) return false;
        l++;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(l > r) return false;
        r--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(l > r) return -1;
        return ss[l];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(l > r) return -1;
        return ss[r];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(l > r) return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(r - l + 1 >= c) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */