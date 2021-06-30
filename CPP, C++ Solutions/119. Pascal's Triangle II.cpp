// TC - O(N)
// SC - O(N)
// Where n = rowIndex
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        long ncr = 1;
        for(int i = 1; i <= rowIndex; i++) {
            ncr *= (rowIndex-i+1);
            ncr /= i;
            res.push_back(ncr);
        }
        return res;
    }
};