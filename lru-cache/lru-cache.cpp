struct Listnode {
    int key, val;
    Listnode *next, *prev;
    Listnode(int _key, int _val) {
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
private:
    int totalCapacity, currCapacity;
    unordered_map<int, Listnode*> mp;
    Listnode *front, *tail;
public:
    LRUCache(int capacity) {
        totalCapacity = capacity;
        currCapacity = 0;
        mp.clear();
        front = new Listnode(0, 0);
        tail = new Listnode(0, 0);
        front -> next = tail;
        tail -> prev = front;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            Listnode *temp = mp[key];
            int ans = temp->val;
            
            deleteNode(temp);
            mp.erase(key);
            
            currCapacity--;
            
            put(key, ans);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            deleteNode(mp[key]);
            mp.erase(key);
            currCapacity--;
            put(key, value);
        }
        else if(currCapacity < totalCapacity) {
            currCapacity++;
            
            Listnode *node = new Listnode(key, value);
            Listnode *nextNode = front->next;
            
            front -> next = node;
            node -> prev = front;
            nextNode -> prev = node;
            node -> next = nextNode;
            
            mp[key] = node;
        }
        else {
            Listnode *lastNode = tail -> prev;
            mp.erase(lastNode->key);
            deleteNode(lastNode);
            currCapacity--;
            put(key, value);
        }
    }
    
    void deleteNode(Listnode *ptr) {
        Listnode *prevNode = ptr -> prev;
        Listnode *nextNode = ptr -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// DLL + unorderd_map