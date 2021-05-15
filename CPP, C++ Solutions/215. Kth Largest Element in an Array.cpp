class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    /*** priority_queue<data_type, container, comparator func>; ***/
        
    /******************************************************
        // Max Heap Solution
        // SC : O(n)
        // Tc : O(n + K*log(n))
        priority_queue<int> maxq(nums.begin(), nums.end());
        while(--k) maxq.pop();
        return maxq.top();
    ********************************************************/
        
        
    /*********************************************************
        // MIN Heap Solution
        // Space - O(K)
        // Time - O(n*logK)
        priority_queue<int, vector<int>, greater<int> > minq;
        for(int i: nums) {
            if(minq.size() < k) minq.push(i);
            else {
                if(minq.top() < i) {
                    minq.pop();
                    minq.push(i);
                }
            }
        }
        return minq.top();
    *****************************************************************/
        
        
    /***************************************************************/
        // MIN Heap Solution without Comparison 
        // Space - O(K + 1)
        // Time - O(n*logK)
        priority_queue<int, vector<int>, greater<int> > minq;
        for(int i: nums) {
            if(minq.size() < k) minq.push(i);
            else {
                minq.push(i);
                minq.pop();
            }
        }
        return minq.top();
    /***************************************************************/
    }
};