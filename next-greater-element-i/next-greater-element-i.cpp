class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++) {
            index[nums2[i]] = i;
        }
        vector<int> nextGreater(n, -1);
        stack<int> stk;
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && stk.top() < nums2[i]) {
                stk.pop();
            }
            if(stk.empty())
                nextGreater[i] = -1;
            else 
                nextGreater[i] = stk.top();
            stk.push(nums2[i]);
        }
        vector<int> answer;
        for(int i = 0; i < nums1.size(); i++) {
            answer.push_back(nextGreater[index[nums1[i]]]);
        }
        return answer;
    }
};