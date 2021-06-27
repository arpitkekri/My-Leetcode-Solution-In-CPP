// TC - O(N*M) 
// SC - O(M)
// N = s.size(), M = part.size()
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();
        int f = 1;
        while(f) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == part[0]) {
                    // O(m) extra space for temp
                    string temp = s.substr(i, m);
                    if(temp == part) {
                        count++;
                        s = s.substr(0, i) + s.substr(i+m);
                        n = s.size(); 
                     }
                }
            }
           if(count == 0) f = 0; 
        }
       return s;
    }
};