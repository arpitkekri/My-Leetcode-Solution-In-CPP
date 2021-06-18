/********* Method -1 (brute Force) **********************
// TC- O(NlogN)
// SC - O(N)
class Solution {
public:
    int countOnes(int n) {
        int count = 0;
        while(n > 0) {
            if(n%2) count++;
            n /= 2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 1; i <= n; i++)
            res[i] = countOnes(i);
        return res;
    }
};
*******************************************************/

/************* Method-2(DP solution, TC-O(N), SC-O(N)) ********/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 1; i <= n; i++)
            res[i] = res[i/2] + i%2;
        return res;
    }
};