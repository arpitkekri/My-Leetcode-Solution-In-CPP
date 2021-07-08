// TC - O(N^2)
// SC - O(N^2)
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        // max size of result is 100*100 when n = 100 so N^2
        int n = nums.size();
        
        for(int i = 0; i < n/2; i++)
            for(int j = 0; j < nums[2*i]; j++)
                res.push_back(nums[2*i+1]);
        
        return res;
    }
};