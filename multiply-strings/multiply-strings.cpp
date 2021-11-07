class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        
        int n = num1.size();
        int m = num2.size();
        
        string res = "";
        for(int i = 0; i < m+n; i++)
            res.push_back('0');
        
        for(int i = m-1; i >= 0; i--) {
            int multi = num2[i] - '0';
            int startIdx = m-1-i;
            for(int j = n-1; j >= 0; j--) {
                int currIdx = startIdx + (n-1-j);
                int carry = res[currIdx] - '0';
                int number = (num1[j]-'0') * multi + carry;
                carry = number / 10;
                number = number %10;
                res[currIdx] = '0' + number;
                res[currIdx+1] += carry;
            }
        }
        
        while(res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};