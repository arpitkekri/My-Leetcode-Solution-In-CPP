class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        int n = temperatures.size();
        vector<int> waitDays(n, 0);
        for(int i = n-1; i >= 0; i--) {
            if(stk.empty()) 
                stk.push({temperatures[i], i});
            else {
                while(!stk.empty() && stk.top().first <= temperatures[i])
                    stk.pop();
                if(!stk.empty())
                    waitDays[i] = stk.top().second - i;
                stk.push({temperatures[i], i});
            }
        }
        return waitDays;
    }
};