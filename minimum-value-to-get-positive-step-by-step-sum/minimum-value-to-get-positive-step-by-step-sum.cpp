class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minVal = 0;
        for(int num: nums) {
            sum += num;
            minVal = min(minVal, sum);
        }
        return max(1, 1-minVal);
    }
};