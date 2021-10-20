class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int minElt = INT_MAX, n = nums.size();
        for(auto num: nums) {
            sum += num;
            minElt = min(minElt, num);
        }
        return sum - n*minElt;
    }
};