// TC - O(N*log(1e7))
// SC - O(1)
class Solution {
public:
    bool check(int speed, vector<int>& dist, double hour) {
        double ans = 0;
        int n = dist.size();
        for(int i = 0; i < n-1; i++) {
            if(dist[i] % speed == 0) ans += dist[i]/speed;
            else ans += (dist[i]/speed) + 1;
        }
        ans += double(dist[n-1])/speed;
        return ans <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int lo = 1, hi = 1e7, mid;
        
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            if(check(mid, dist, hour))
                hi = mid;
            else lo = mid + 1;
        }
        
        if(check(lo, dist, hour)) return lo;
        return -1;
    }
};