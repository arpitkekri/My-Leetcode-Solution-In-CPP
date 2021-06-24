// N = s.length, M = sum(words.length*words[i].length)
// TC - O(M*logN)
// SC - O(N)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n, count = 0;
        vector<vector<int>> vec(26);
        
        for(int i = 0; i < s.size(); i++)
            vec[s[i]-'a'].push_back(i);
    
        for(int i = 0; i < words.size(); i++) {
            int f = 1;
            int idx = -1;
            for(int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                int n = vec[c-'a'].size();
                if(n == 0) {f=0; break;}
                int lo = 0, hi = n-1;
                while(lo < hi) {
                    int mid = lo + (hi-lo)/2;
                    if(vec[c-'a'][mid] > idx) 
                        hi = mid;
                    else lo = mid+1;
                }
                if(vec[c-'a'][lo] > idx) idx = vec[c-'a'][lo];
                else {f=0; break;}
            }
            if(f) count++;
        }
        return count;
    }
};