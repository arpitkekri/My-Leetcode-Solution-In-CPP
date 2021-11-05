class Solution {
public:
    bool isPossible(long long mid, int n) {
        return (mid*(mid+1))/2 <= (long long)n;
    }
    int arrangeCoins(int n) {
        long long lo = 1, hi = 1e5, mid;
        while(lo < hi) {
            mid = lo + (hi-lo+1)/2;
            if(isPossible(mid, n))
                lo = mid;
            else 
                hi = mid-1;
        }
        return lo;
    }
};