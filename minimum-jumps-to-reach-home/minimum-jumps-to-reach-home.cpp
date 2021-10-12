class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x ==  0) return 0;
        unordered_set<int> notAllowed(forbidden.begin(), forbidden.end());
        
        // pos, steps, backAllowed
        queue<vector<int>> q;
        q.push({0, 0, 1});
        
        set<pair<int, int>> visited;
        visited.insert({0, 1});
        
        while(!q.empty()) {
            vector<int> t = q.front();
            q.pop();
            
            if(t[0] + a == x) return t[1] + 1;
            
            if(t[0] + a >= 0 && t[0] + a <= 100000 && notAllowed.find(t[0] + a) == notAllowed.end() && visited.find({t[0]+a, 1}) == visited.end()) {
                visited.insert({t[0]+a, 1});
                q.push({t[0]+a, t[1] + 1, 1});
            }
            if(t[2] == 1 && t[0] - b == x) return t[1] + 1;
            
            if(t[2] == 1 && t[0]-b >= 0 && notAllowed.find(t[0]-b) == notAllowed.end() && visited.find({t[0]-b, 0}) == visited.end()) {
                visited.insert({t[0]-b, 0});
                q.push({t[0]-b, t[1] + 1, 0});
            }
        }
        return -1;
    }
};