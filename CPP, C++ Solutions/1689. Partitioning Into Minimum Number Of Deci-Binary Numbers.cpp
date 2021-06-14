// TC - O(N)
// SC - O(1)
class Solution {
public:
    int minPartitions(string n) {
        // int sz = n.size();
        // int res = 0;
        // for(int i = sz-1; i >= 0; i--) {
        //     res = max(res, n[i]-'0');
        //     if(res == 9) break;
        // }
        // return res;
        return *max_element(n.begin(), n.end()) - '0';
    }
};