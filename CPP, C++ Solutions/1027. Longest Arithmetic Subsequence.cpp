/************ Method-1 (TLE because of map, TC-O(N^2), SC-O(N^2)) ************
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), cd, res = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                cd = nums[i] - nums[j];
                if(dp[j].find(cd) == dp[j].end())
                    dp[i][cd] = max(dp[i][cd], 2);
                else 
                    dp[i][cd] = max(dp[i][cd], 1 + dp[j][cd]);
                
                res = max(res, dp[i][cd]);
            }
        }
        return res;
    }
};

********************************************************************************/


/*************** Method-2 (Use 2D-vector, TC-O(N^2), SC-O(N*1001)) ***************/
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), cd, res = 0;
        
        // We can pass nums array and find min and max elt to do more space optimization 
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                cd = nums[i] - nums[j];
                dp[i][cd+500] = max(2, 1+dp[j][cd+500]);
                res = max(res, dp[i][cd+500]);
            }
        }
        return res;
    }
};