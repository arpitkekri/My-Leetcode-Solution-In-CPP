// TC - O(N)
// SC - O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) sum += chalk[i];
        
        if(sum == 1) return 0;
        
        k = k%sum;
        if(k == 0) return 0;
        
        int i;
        for(i = 0; i < n; i++) {
            if(k < chalk[i]) break;
            else k -= chalk[i];
        }
        return i;
    }
};