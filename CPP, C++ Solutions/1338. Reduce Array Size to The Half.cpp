// TC - O(nlogn)
// SC - O(n)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>m;
        for(int i = 0; i < n; i++)
            m[arr[i]]++;
        
        vector<int> a;
        for(auto &elt: m)
            a.push_back(elt.second);
        
        sort(a.begin(), a.end());
        int sz = a.size();
        int count = 0, ans = 0;
        for(int i = sz-1; i >= 0; i--) {
            ans++;
            count += a[i];
            if(count >= n/2) break;
        }
        return ans;
    }
};