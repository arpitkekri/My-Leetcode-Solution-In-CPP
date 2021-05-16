// TC - O(N^2)
// SC - O(1)
/***************************************************************
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++) {
            int gasRem = gas[i] - cost[i];
            int itr = (i+1)%n;
            while(gasRem >= 0 && itr != i) {
                gasRem += gas[itr];
                gasRem -= cost[itr];
                if(gasRem < 0) break;
                itr = (itr+1)%n;
            }
            if(itr == i && gasRem >= 0) return itr;
        }
        return -1;
    }
};
*************************************************************/

// TC - O(N)
// SC - O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while(start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};