/*
class compare {
    public:
        bool operator()(){
            return .. //distance logic
        }
}
*/
class Solution {
public:
    // struct greater{
    //     bool operator()(){
    //         return 
    //     }
    // }
    typedef vector<int> point;
    struct compare {
        bool operator()(point a, point b) {
            // return // distance logic
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort(start, end, compare);
        // priority_queue<p, vector<point>, greater<>>minq;
        // TC - O(N) + O(K*logN) = O(N + K*logN)
        // SC - O(logN + N^2) = O(N^2)
        priority_queue<point, vector<point>, compare> minq(points.begin(), points.end());
        vector<point> res;
        while(k--) {
            res.push_back(minq.top());
            // TC - O(K*logN);
            minq.pop();
        }
        return res;
    }
};