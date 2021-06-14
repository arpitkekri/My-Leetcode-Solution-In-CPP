// TC - O(N)
// SC - O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) 
                continue;
            else {
                a = max(a, triplets[i][0]);
                b = max(b, triplets[i][1]);
                c = max(c, triplets[i][2]);
            }
        }
        if(a == target[0] && b == target[1] && c == target[2]) return true;
        return false;
    }
};