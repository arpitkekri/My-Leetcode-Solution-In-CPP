class Solution {
public:
    typedef long long int ll; 
    int nthUglyNumber(int n) {
        // 1, 2, 3, 5
        // Good Question
        priority_queue<ll, vector<ll>, greater<>> minq;
        minq.push(1);
        if(n == 1)  return 1;
        ll cnt = 1;
        while(cnt <  n) {
            ll temp = minq.top();
            minq.pop();
            if(temp%2 == 0) {
                minq.push(temp*2);
            } else if(temp%3 == 0) {
                minq.push(temp*2);
                minq.push(temp*3);
            }
            else {
                minq.push(temp*2);
                minq.push(temp*3);
                minq.push(temp*5);
            }
            cnt++;
        }
        return minq.top();
    }
};