// TC - O(NlogN)
// SC - O(N)

class Solution {
public:
    bool isSubsequence(string &s, string &p, vector<int>& removable, int idx) {
        unordered_set<int> st;
        for(int i = 0; i <= idx; i++) st.insert(removable[i]);
        
        int i = 0, j = 0;
        for(i = 0; i < s.size() && j < p.size(); i++) {
            if(st.find(i) != st.end()) continue;
            if(s[i] == p[j]) j++;
        }
        return (j==p.size());
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        
        int lo = 0, hi = n-1, mid;
        while(lo < hi) {
            mid = lo + (hi-lo+1)/2;
            if(isSubsequence(s, p, removable, mid))
                lo = mid;
            else hi = mid-1;
        }
        if(isSubsequence(s, p, removable, lo)) return lo+1;
        return lo;
    }
};