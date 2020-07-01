/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月05日 星期日 17时10分41秒
 ************************************************************************/

struct Node {
    int cnt, time, key, value;
    Node(int a, int b, int c, int d) {
        cnt = a;
        time = b;
        key = c;
        value = d;
    }
    Node() {}
    bool operator < (const Node& s) const {
        return cnt == s.cnt ? time < s.time : cnt < s.cnt;
    }
};

class LFUCache {
    int capacity, time;
    unordered_map <int, Node> key_table;
    set <Node> ss;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        ss.clear();
    }
    
    int get(int key) {
        if(capacity == 0) return -1;
        auto it = key_table.find(key);
        if(it == key_table.end()) return -1;
        Node p = it->second;
        ss.erase(p);
        p.cnt++;
        p.time = ++time;
        ss.insert(p);
        it->second = p;
        return p.value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return ;
        auto it = key_table.find(key);
        if(it == key_table.end()) {
            if(key_table.size() == capacity) {
                key_table.erase(ss.begin()->key);
                ss.erase(ss.begin());
            }
            Node p = Node(1, ++time, key, value);
            key_table.insert(make_pair(key, p));
            ss.insert(p);
        }
        else {
            Node p = it->second;
            ss.erase(p);
            p.cnt++;
            p.time = ++time;
            p.value = value;
            ss.insert(p);
            it->second = p;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
