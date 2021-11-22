class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n), nsr(n);
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(stk.empty())
                nsl[i] = -1;
            else
                nsl[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(stk.empty())
                nsr[i] = n;
            else 
                nsr[i] = stk.top();
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, heights[i]*(nsr[i] - nsl[i] - 1));
        }
        return ans;
    }
};