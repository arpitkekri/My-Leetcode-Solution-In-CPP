// TC - O(N^2) + O(N*logN) = O(N^2)
// SC - O(N) in sorting
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort this heightwise than count wise
        sort(people.begin(), people.end(), [=](const vector<int> &a, const vector<int> &b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        // vector<vector<int>> res(people.size());
        vector<int> temp;
        for(int i = 0; i < people.size(); i++) {
            // put this person at the right slot and shift everything 
            int slot = people[i][1];
            temp = people[i];
            for(int j = i; j > slot; j--)
                people[j] = people[j-1];
            people[slot] = temp;
        }
        return people;
    }
};