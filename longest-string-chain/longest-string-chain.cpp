class Solution {
public:
    bool isGettingWord(string &curr, string &temp) {
        int j = 0;
        int deleteCount = 0;
        for(int i = 0; i < curr.size(); i++) {
            if(curr[i] == temp[j]) j++;
            else deleteCount++;
            if(deleteCount > 1) return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [=](const string &a, const string &b){
            return a.size() < b.size();
        });
        int n = words.size(), ans = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            string curr = words[i];
            for(int j = i-1; j >= 0; j--) {
                string temp = words[j];
                if(curr.size() == temp.size()) continue;
                else if(curr.size()-temp.size() == 1) {
                    if(isGettingWord(curr, temp))
                        dp[i] = max(dp[i], dp[j]+1);
                }
                else break;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};