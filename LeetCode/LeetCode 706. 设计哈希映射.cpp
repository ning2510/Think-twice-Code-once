struct Node {
    int key, val;
    Node *next;
    Node(int a, int b) : key(a), val(b), next(nullptr) {}
};

class MyHashMap {
public:
    int mod = 1e5 + 7;
    vector <Node*> ss;

    /** Initialize your data structure here. */
    MyHashMap() {
        ss.resize(mod, new Node(-1, -1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int cnt = key % mod;
        Node* p = ss[cnt];
        while(p) {
            if(p->key == key) {
                p->val = value;
                return ;
            }
            if(p->next == nullptr) break;
            p = p->next;
        }
        Node* node = new Node(key, value);
        p->next = node;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int cnt = key % mod;
        Node* p =ss[cnt];
        while(p) {
            if(p->key == key) return p->val;
            if(p->next == nullptr) break;
            p = p->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int cnt = key % mod;
        Node* p = ss[cnt];
        while(p) {
            if(p->key == key) {
                p->val = -1;
                return ;
            }
            if(p->next == nullptr) break;
            p = p->next;
        }
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */