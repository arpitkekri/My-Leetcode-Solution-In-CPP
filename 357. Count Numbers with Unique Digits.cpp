// Simple Math solution using p & c

class Solution {
public:
    int countThisDigit(int n) {
        if(n == 1) return 9;
        int res = 9;
        n--;
        for(int i = 0; i < n; i++) {
            res *= 9-i;
        }
        return res;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 0;
        for(int i = n; i > 0; i--)
            ans += countThisDigit(i);
        return ans+1;
    }
};