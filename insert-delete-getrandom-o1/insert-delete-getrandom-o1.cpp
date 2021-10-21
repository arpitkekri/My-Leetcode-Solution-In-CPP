class RandomizedSet {
public:
    map<int, int> mp;
    vector<int> arr;
    RandomizedSet() {
        mp.clear();
        arr.clear();
    }
    
    bool insert(int val) {
        if(mp.count(val))
            return false;
        mp[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    // bool remove(int val) {
    //     if(mp.count(val)) {
    //         int lastElt = arr.back();
    //         int idx = mp[val];
    //         arr[idx] = lastElt;
    //         mp[lastElt] = idx;
    //         mp.erase(val);    
    //         arr.pop_back();
    //         return true;
    //     }
    //     return false;
    // }
     bool remove(int val) {
        if(mp.count(val)) {
            int removeIdx = mp[val];
            swap(arr[(int)arr.size()-1], arr[removeIdx]);
            mp[arr[removeIdx]] = removeIdx;
            mp.erase(val);  
            arr.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = arr.size();
        int randIdx = rand()%n;
        return arr[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */