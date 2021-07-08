// Method - 1 TC - O(NlogN)  SC - O(N)

/*class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        vector<double> time(n);
        for(int i = 0; i < n; i++)
            time[i] = (double) dist[i]/speed[i];
        
        sort(time.begin(), time.end());
        
        int i;
        for(i = 0; i < n; i++)
            if(time[i] <= i) break;
        
        return i;
    }
};*/

// Method-2 TC-O(NlogN), SC - O(1)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        for(int i = 0; i < n; i++)
            dist[i] = dist[i]/speed[i] - (dist[i]%speed[i] == 0);
        
        sort(dist.begin(), dist.end());
        
        int i;
        for(i = 0; i < n; i++)
            if(dist[i] < i) break;
        
        return i;
    }
};