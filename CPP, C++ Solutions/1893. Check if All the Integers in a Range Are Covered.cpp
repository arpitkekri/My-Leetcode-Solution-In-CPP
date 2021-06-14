// TC - O(N^2)
// SC - O(N)
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> visited(51, false);
        int n = ranges.size();
        for(int i = 0; i < n; i++)
            for(int j = ranges[i][0]; j <= ranges[i][1]; j++)
                visited[j] = true;

        for(int i = left; i <= right; i++)
            if(!visited[i]) return false;
        return true;
    }
};