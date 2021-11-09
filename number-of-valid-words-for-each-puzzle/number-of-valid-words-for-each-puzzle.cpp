class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans(puzzles.size(), 0);
        
        map<int, int> mp;
        for(auto word: words) {
            int bitmask = 0;
            for(int i = 0; i < word.size(); i++)
                bitmask |= (1 << (word[i]-'a'));
            mp[bitmask]++;
        }
        
        for(int i = 0; i < puzzles.size(); i++) {
            int bitmask = 0;
            for(int j = 1; j < puzzles[i].size(); j++) {
                bitmask |= (1 << (puzzles[i][j] - 'a'));
            }
            int first = 1 << (puzzles[i][0] - 'a');
            ans[i] += mp[first];
            int submask = bitmask;
            for(int s = bitmask; s; s = (s-1) & bitmask) {
                ans[i] += mp[s | first];
            }
            // while(submask >= 0) {
            //     if(mp.count(submask | first)) {
            //         ans[i] += mp[submask | first];
            //     }
            //     submask = (submask-1) & bitmask;
            // }
        }
        
        return ans;
    }
};