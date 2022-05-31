class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n <= k) return false;
        unordered_set<string> unique;
        string bcode = s.substr(0, k);
        unique.insert(bcode);
        
        //sliding window technique
        for(int i = k; i < n; i++) {
            bcode.erase(bcode.begin());
            bcode.push_back(s[i]);
            unique.insert(bcode);
        }
        
        if(unique.size() == (1 << k)) return true;
        return false;
    }
};