// TC - O(N*N)
// SC - O(26)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++) {
            string s = words[i];
            for(int j = 0; j < s.size(); j++)
                freq[s[j]-'a']++;
        }
        for(int i = 0; i < 26; i++)
            if(freq[i]%n != 0) return false;

        return true;
    }
};