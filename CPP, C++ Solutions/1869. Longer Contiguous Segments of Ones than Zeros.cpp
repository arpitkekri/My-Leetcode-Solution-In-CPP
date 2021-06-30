// TC - O(N)
// SC - O(1)
class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        int zeroLen = 0, zeroCount = 0;
        int oneLen = 0, oneCount = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                oneCount++;
                zeroCount = 0;
            }
            else {
                zeroCount++;
                oneCount = 0;
            }
            zeroLen = max(zeroLen, zeroCount);
            oneLen = max(oneLen, oneCount);
        }
        return oneLen > zeroLen;
    }
};