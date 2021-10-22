class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        vector<char> letter;
        for(auto itr: freq) {
            letter.push_back(itr.first);
        }
        sort(letter.begin(), letter.end(), [&](const char a, const char b){
            return freq[a] > freq[b];
        });
        // vector<pair<int, int>> freqSort;
        // for(int i = 0; i < 256; i++) {
        //     if(freq[i] > 0) {
        //         freqSort.push_back({freq[i], i});
        //     }
        // }
        // sort(freqSort.rbegin(), freqSort.rend());
        s = "";
        for(auto itr: letter) {
            int f = freq[itr];
            int c = itr;
            // char c = itr.second;
            for(int i = 0; i < f; i++) 
                s.push_back(c);
        }
        return s;
    }
};