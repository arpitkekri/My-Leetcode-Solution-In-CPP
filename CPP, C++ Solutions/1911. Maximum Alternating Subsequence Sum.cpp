class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<int> dp;
        int start = 0;
        int f = 0;
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(flag == 0) {
                int f = nums[i];
                while(i+1 < n && nums[i+1] >= nums[i]) {
                    f = nums[i+1];
                    i = i+1;
                }
                dp.push_back(f);
                flag = 1;
            }
            else {
                int s = nums[i];
                while(i+1 < n && nums[i+1] <= nums[i]) {
                    i++;
                    s = nums[i];
                }
                dp.push_back(s);
                flag = 0;
            }
        }
        
        int m = dp.size();
        if(m%2==0) m--;
        for(int i = 0; i < m; i++) {
            if(i%2==0) res += dp[i];
            else res -= dp[i];
        }
        return res;
    }
};