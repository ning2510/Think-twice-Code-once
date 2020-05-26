struct DLinkNode {
    int key, val;
    DLinkNode* next, *pre;
    DLinkNode(): key(0), val(0), pre(nullptr), next(nullptr) {}
    DLinkNode(int a, int b): key(a), val(b), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    unordered_map <int, DLinkNode*> cache;
    DLinkNode* head;
    DLinkNode* tail;
    int size, capacity;

    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        DLinkNode* node = cache[key];
        MoveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)) {
            DLinkNode* node = new DLinkNode(key, value);
            cache[key] = node;
            AddToHead(node);
            size++;
            if(size > capacity) {
                DLinkNode* del = DeleteTail();
                cache.erase(del->key);
                size--;
            } 
        }
        else {
            DLinkNode* node = cache[key];
            node->val = value;
            MoveToHead(node);
        }
    }

    void AddToHead(DLinkNode* node) {
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    void Deletenode(DLinkNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void MoveToHead(DLinkNode* node) {
        Deletenode(node);
        AddToHead(node);
    }

    DLinkNode* DeleteTail() {
        DLinkNode* node = tail->pre;
        Deletenode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */