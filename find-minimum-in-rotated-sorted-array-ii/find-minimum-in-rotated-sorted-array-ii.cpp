class Solution {
public:
    int findMin(vector<int>& nums) {
        int minEle = 1e6;
        for(auto num: nums) {
            minEle = min(minEle, num);
        }
        return minEle;
    }
};