class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool isPos = true;
        string news = "";
        long long ans = 0;
        int flag = 0;
        int flag2 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ' && flag2 == 0) continue;
            else if(s[i] == '+') {
                flag2 = 1;
                if(news == "" && flag == 0) {isPos = true; flag = 1;}
                else break;
            }
            else if(s[i] == '-') {
                flag2 = 1;
                if(news == "" && flag == 0) {isPos = false; flag = 1;}
                else break;
            }
            else if(s[i] - '0' <= 9 && s[i] - '0' >= 0) {
                flag2 = 1;
                news += s[i];
            }
            else break;
        }
        if(news.size() == 0) return 0;
        
        ans = news[0] - '0';
        for(int i = 1; i < news.size(); i++) {
            ans = ans*10 + (news[i] - '0');
            if(ans > INT_MAX) {
                if(isPos) return INT_MAX;
                else return INT_MIN;
            }
        }
        if(isPos) return ans;
        else return -ans;
    }
};