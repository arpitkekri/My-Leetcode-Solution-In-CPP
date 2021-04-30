class Solution {
public:
    string reverseWords(string s) {
        // ************** O(n) time and space *****************
        /* 
        int n = s.size();
        int flag = 0, isF = 1;
        string str = "", ans = "";
        
        for(int i = 0; i < n; i++)  {
            if(s[i] != ' ' && flag == 0) {
                str = s[i];
                flag = 1;
            }
            else if(s[i] != ' ' && flag == 1)
                str += s[i];
            else {
                if(str.size() > 0) {
                    if(isF == 1) { ans = str; isF = 0;}
                    else ans = str + " " + ans;
                }
                str = "";
            }
        }
        if(!str.empty())
            isF == 1? ans = str: ans = str + " " + ans;
        return ans;
        */
        
        
        // ************* Inplace Solution O(n) Time, O(1) space *****************
        reverse(s.begin(), s.end());
        int flag = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(flag == 0) flag = 1;
                else {
                    s.erase(i, 1);
                    i--;
                }
            }
            else flag = 0;
        }
        int pos = 0;
        while(s[pos] == ' ') s.erase(pos, 1);
        pos = s.size() - 1;
        while(s[pos] == ' ') s.erase(pos, 1);
        for(int i = 0; i < s.size(); i++) {
            int j = i;
            while(j+1 < s.size() && s[j+1] != ' ') j++;
            reverse(s.begin()+i, s.begin()+j+1);
            i = j+1;
        }
        return s;
    }
};