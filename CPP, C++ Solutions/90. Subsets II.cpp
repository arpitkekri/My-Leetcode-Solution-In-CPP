class Solution {
public:
    vector<vector<int>> f(vector<int> &nums, int i, int end, int &count) {
        if(i == end) {
            // base case returns count = 1 
            // here count is number of same element it seen so far
            // e.g. for 44 -> count = 2
            // e.g. 444 -> count = 3 
            count = 1;
            return {{}, {nums[end]}};
        }
        vector<vector<int>> c2 = f(nums, i+1, end, count);
        vector<vector<int>> c1;
        
        // when next element is not same than reset count to 1 and if same then increase by 1 
        if(nums[i] != nums[i+1]) count = 1;
        else count++;
        
        // if count = 1 means new element so we have to push nums[i] in all the C2 elements 
        // if count > 1 than we need to divede C2 and insert nums[i] in last n/count elements;
        // e.g. -> if count = 2 then we insert nums[i] to last half elements
        // e.g. -> if count = 3 then we insert nums[i] to last 1/3 elements
        // x is position till than we have to take C2
        
        int x = c2.size() - c2.size()/count;
        for(int j = c2.size()-1; j >= x; j--) {
            c1.push_back(c2[j]);
            c1[c1.size()-1].push_back(nums[i]);
        }
        
        vector<vector<int>> res = c2;
        for(int j = 0; j < c1.size(); j++) 
            res.push_back(c1[j]);
        return res;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count;
        vector<vector<int>> res = f(nums, 0, nums.size()-1, count);
        return res;
    }
};