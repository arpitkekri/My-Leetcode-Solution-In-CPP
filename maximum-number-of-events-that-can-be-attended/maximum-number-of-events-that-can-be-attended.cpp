class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int ans = 0, day = 0, i = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        while(!pq.empty() || i < n) {
            if(pq.empty())
                day = events[i][0];
            
            // push all events which is stared
            while(i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }
            
            // pop 1 event to attend today
            pq.pop();
            ans++; day++;
            
            // pop all events which is closed
            while(!pq.empty() && pq.top() < day)
                pq.pop();
        }
        return ans;
    }
};