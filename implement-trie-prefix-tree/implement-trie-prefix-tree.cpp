class Trie {
private: 
    struct trieNode {
        trieNode* next[26] = {NULL};
        bool isEndHere = false;
    };
    trieNode *root;
public:
    Trie() {
        root = new trieNode();
    }
    
    void insert(string word) {
        trieNode *temp = root;
        
        int n = word.size();
        for(int i= 0; i < n; i++) {
            char c = word[i];
            if(temp->next[c-'a'] == NULL) {
                temp -> next[c-'a'] = new trieNode();
            }
            temp = temp->next[c-'a'];
        }
        temp -> isEndHere = true;
    }
    
    bool search(string word) {
        trieNode *temp = root;
        
        int n = word.size();
        for(int i= 0; i < n; i++) {
            char c = word[i];
            if(temp->next[c-'a'] == NULL) return false;
            temp = temp->next[c-'a'];
        }
        if(temp -> isEndHere == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode *temp = root;
        
        int n = prefix.size();
        for(int i= 0; i < n; i++) {
            char c = prefix[i];
            if(temp->next[c-'a'] == NULL) return false;
            temp = temp->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */