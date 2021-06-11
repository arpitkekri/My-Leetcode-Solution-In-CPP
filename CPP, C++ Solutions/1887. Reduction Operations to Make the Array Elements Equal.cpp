// TC - O(NlogN) in sorting + O(N) ==> O(NlogN)
// SC - O(N) in sorting
class Solution {
public:
    void merge(vector<int>& nums, int lo, int mid, int hi) {
        vector<int> left;
        vector<int> right;
        
        for(int i = lo; i <= mid; i++)
            left.push_back(nums[i]);
        
        for(int i = mid+1; i <= hi; i++) 
            right.push_back(nums[i]);
        
        int k = lo;
        int i = 0, j = 0;
        while(i < left.size() || j < right.size()) {
            if(i == left.size()) {
                nums[k] = right[j];
                j++;
            }
            else if(j == right.size()) {
                nums[k] = left[i];
                i++;
            }
            else if(left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            }
            else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
    }
    
    void mergeSort(vector<int>& nums, int lo, int hi) {
        if(lo >= hi) return;
        int mid = lo + (hi-lo)/2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, hi);
        merge(nums, lo, mid, hi);
    }
    
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        // mergeSort(nums, 0,  n-1); <- It will give TLE
        sort(nums.begin(), nums.end());
        
        int counter = 0;
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) res += counter;
            else{
                counter++;
                res += counter;
            }
        }
        return res;
    }
};