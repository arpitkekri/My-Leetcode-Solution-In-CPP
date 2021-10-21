class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        if(s.count(val))
            return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val)) {
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = s.size();
        int randNo = rand()%n;
        auto itr = s.begin();
        advance(itr, randNo);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */