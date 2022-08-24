class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()) return 0;
        s.insert(val);
        return 1;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end()) return 0;
        s.erase(val);
        return 1;
    }
    
    int getRandom() {
        // int n = s.size();
        int a = rand() % s.size();
        auto it = s.begin();
        advance(it, rand() % s.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
