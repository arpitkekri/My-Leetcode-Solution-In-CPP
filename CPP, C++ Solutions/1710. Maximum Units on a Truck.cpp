// TC - O(nlogn)
// SC - O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [=](const vector<int> &a, const vector<int> &b){
            return a[1] > b[1];
        });
        int n = boxTypes.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(boxTypes[i][0] <= truckSize) {
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else if(truckSize > 0) {
                ans += truckSize*boxTypes[i][1];
                truckSize = 0;
            }
            else break;
        }
        return ans;
    }
};