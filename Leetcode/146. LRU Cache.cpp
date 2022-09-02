// Definition for doubly-linked list.
struct DoublyListNode {
    pair<int,int> val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(pair<int,int> x) : val(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    int n = 0;
    DoublyListNode *l = nullptr, *r = nullptr;
    unordered_map<int, DoublyListNode*> m;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        auto t = m[key];
        int ans = t->val.second;
        if(m.size() == 1) return ans;
        
        auto p = t->prev, nx = t->next;
        if(p) p->next = nx;
        if(nx) nx->prev = p;
        if(t == l) l = nx;
        if(t == r) r = p;
        
        t->next = nullptr;
        t->prev = r;
        r->next = t;
        r = t;
        
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            auto t = m[key];
            auto p = t->prev, nx = t->next;
            if(p) p->next = nx;
            if(nx) nx->prev = p;
            if(t == l) l = nx;
            if(t == r) r = p;
            
            t->next = nullptr;
            t->prev = nullptr;
            
            m.erase(t->val.first);
            n++;
        }
        auto t = new DoublyListNode({key,value});
        if(n <= 0) {
            m.erase(l->val.first);
            if(l == r) r = r->next;
            l = l->next;
        }
        
        if(r == nullptr) {
            r = t;
            l = t;
        } else {
            t->prev = r;
            r->next = t;
            r = t;
        }
        m[key] = t;
        if(n) n--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
