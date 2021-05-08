class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int mx = 0;
        vector<bool> res(n);
        for(auto candy: candies) mx = max(mx, candy);
        for(int i = 0; i < n; i++)
            res[i] = candies[i] + extraCandies >= mx ? true: false;
        return res;
    }
};