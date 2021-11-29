class Solution {
public:
    vector<int> kmp(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for(int i = 1; i < n; i++) {
            int j = lps[i-1];
            while(j > 0 && s[i] != s[j]) {
                j = lps[j-1];
            }
            if(s[i] == s[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n == 0) return 0;
    
        vector<int> lps = kmp(needle);
        
        int j = 0, i = 0;
        while(i < m) {
            if(haystack[i] == needle[j]) {
                j++;
                i++;
                continue;
            }
            if(j == n) return (i-n);
            
            if(j == 0)
                i++;
            else j = lps[j-1];
        }
        if(j == n)
            return (i-n);
        
        return -1;
        
    }
};