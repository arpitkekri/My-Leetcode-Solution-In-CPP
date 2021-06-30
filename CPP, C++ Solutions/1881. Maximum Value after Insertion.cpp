// TC - O(N)
// SC - O(1)
class Solution {
public:
    string maxValue(string n, int x) {
        int i = 0;
        
        if(n[0] == '-') {
            for(i = 1; i < n.size(); i++)
                if((n[i]-'0') > x) break;
        }
        else {
            for(i = 0; i < n.size(); i++)
                if((n[i]-'0') < x) break;
        }
        
        n = n.substr(0, i) + char('0' + x) + n.substr(i);
        return n;
    }
};