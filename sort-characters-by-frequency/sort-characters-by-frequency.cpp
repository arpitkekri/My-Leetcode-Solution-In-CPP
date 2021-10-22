class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);
        for(int i = 0; i < s.size(); i++) {
            freq[(int)s[i]]++;
        }
        vector<pair<int, int>> freqSort;
        for(int i = 0; i < 256; i++) {
            if(freq[i] > 0) {
                freqSort.push_back({freq[i], i});
            }
        }
        sort(freqSort.rbegin(), freqSort.rend());
        s = "";
        for(auto itr: freqSort) {
            int f = itr.first;
            char c = itr.second;
            s.append(string(f, c));
        }
        return s;
    }
};