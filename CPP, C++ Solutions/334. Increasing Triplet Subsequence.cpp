// TC - O(N)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int smaller = INT_MAX, next_smaller = INT_MAX;
        for(int num: nums) {
            if(num <= smaller) smaller = num;
            else if(num <= next_smaller) next_smaller = num;
            else return true;
        }
        return false;
    }
};