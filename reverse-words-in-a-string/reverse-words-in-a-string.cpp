class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        s = "";
        
        while(getline(ss, word, ' ')) {
            if(word.size()) {
                reverse(word.begin(), word.end());
                s += " " + word;
            }
        }
        s = s.substr(1);
        reverse(s.begin(), s.end());
        return s;
    }
};