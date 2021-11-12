class Solution {
public:
    
    void update(int idx, vector<int> &BIT) {
        while(idx < BIT.size()) {
            BIT[idx]++;
            idx += idx & -idx;
        }
    }
    
    int answer(int idx, vector<int> &BIT) {
        int small = 0;
        while(idx > 0) {
            small += BIT[idx];
            idx -= idx & -idx;
        }
        return small;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> BIT(20005, 0);
        
        for(int i = n-1; i >= 0; i--) {
            res[i] = answer(nums[i] + 10001 - 1, BIT);
            update(nums[i] + 10001, BIT);
        }
        return res;
    }
};