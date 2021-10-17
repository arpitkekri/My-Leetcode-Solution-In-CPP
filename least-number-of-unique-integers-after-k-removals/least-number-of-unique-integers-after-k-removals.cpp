class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> freq;
        for(auto num: arr)
            freq[num]++;
        int n = freq.size();
        vector<pair<int, int>> nums(freq.begin(), freq.end());
        sort(nums.begin(), nums.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });
        int sum = 0, i = 0;
        while(sum < k) {
            sum += nums[i].second;
            if(sum <= k) n--;
            i++;
        }
        return n;
    }
};