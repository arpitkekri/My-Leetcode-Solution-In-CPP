class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.size();
        int m = target.size();
        unordered_map<char, int> mp;
        vector<int> freq(26, 0);
        for(int i = 0; i < m; i++) {
            mp[target[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++; 
        }
        
        int ans = 101;
        for(auto i: mp) {
            ans = min(ans, freq[i.first - 'a']/i.second);
        }
        
        return ans;
    }
};