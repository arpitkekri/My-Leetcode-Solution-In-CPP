// TC - O(log(n))
// SC - O(1)
class Solution {
public:
    long long mod = 1e9+7;
    long long binPow(long long x, long long y) {
        if(y == 0) return 1;
        else if(y%2) return (x*binPow((x*x)%mod, (y-1)/2))%mod;
        return binPow((x*x)%mod, y/2)%mod;
    }
    
    int countGoodNumbers(long long n) {
        if(n&1) return (5*binPow(20, n/2))%mod;
        return binPow(20, n/2)%mod;
    }
};