// TC - O(N)
// SC - O(1)
class Solution {
public:
    long long findNum(string s) {
        int n = s.length();
        long long res = 0;
        for(int i = 0; i < n; i++) {
            res *= 10;
            res += (s[i]-'a');
        }
        return res;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        long long a = findNum(firstWord);
        long long b = findNum(secondWord);
        long long c = findNum(targetWord);
        return (a+b == c);
    }
};