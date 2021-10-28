class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        int i = 0, j;
        for(i = 0; i < nums.size(); i++) {
            mp[nums[i]]--;
            int flag = 0;
            if(mp[target-nums[i]] > 0) {
                for(j = i+1; j < nums.size(); j++)
                    if(nums[j] == target-nums[i])
                        break;
                flag = 1;
            }
            if(flag)
                break;
        }
        return {i, j};
    }
};