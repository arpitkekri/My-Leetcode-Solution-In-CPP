/*********** Method-1 (TC-O(N^2), SC-O(1)) *******************
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        if(satisfaction[n-1] <= 0) return 0;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int counter = 1;
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += counter*satisfaction[j];
                counter++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
*************************************************************/

/***************** Method-2 (DP, TC-O(NlogN), SC-O(N)) *******************
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        if(satisfaction[n-1] <= 0) return 0;
        int ans = 0;
        
        vector<int> suffixSum(n, 0);
        vector<int> dp(n, 0);
        
        suffixSum[n-1] = satisfaction[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixSum[i] = satisfaction[i] + suffixSum[i+1];
        }
        
        dp[n-1] = satisfaction[n-1];
        ans = max(ans, dp[n-1]);
        for(int i = n-2; i >= 0; i--) {
            dp[i] = dp[i+1] + suffixSum[i];
            ans = max(ans, dp[i]);
        }
        return max(ans, 0);
    }
};
***************************************************************/

/*********** Method-3 (DP, TC-O(NlogN), SC-O(1)) *****************/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        if(satisfaction[n-1] <= 0) return 0;
        int ans = 0;
        
        int suffixSum = 0;
        int dp = 0;
        for(int i = n-1; i >= 0; i--) {
            suffixSum += satisfaction[i];
            dp += suffixSum;
            ans = max(ans, dp);
        }
        
        return ans;
    }
};
