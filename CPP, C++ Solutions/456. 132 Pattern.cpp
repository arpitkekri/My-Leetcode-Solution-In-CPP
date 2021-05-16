// TC - O(N)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        stack<int> st;
        int s3 = INT_MIN;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < s3) return true;
            else while(!st.empty() && st.top() < nums[i]) {
                s3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
// Solution Explanation Link - https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.