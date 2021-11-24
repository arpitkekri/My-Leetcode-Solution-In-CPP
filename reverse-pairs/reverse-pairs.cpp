class Solution {
public:
    void merge(vector<int> &nums, int &pairs, int start, int mid, int end) {
        vector<int> left(mid-start+1);
        vector<int> right(end - mid);
        for(int i = start; i <= mid; i++) {
            left[i-start] = nums[i];
        }
        for(int i = mid+1; i <= end; i++) {
            right[i-mid-1] = nums[i];
        }
        
        // count_pairs
        int i = 0, j = 0;
        int left_size = left.size(), right_size = right.size();
        while(i < left_size) {
            while(j < right_size) {
                if(2LL*right[j] < left[i])
                    j++;
                else break;
            }
            pairs += j;
            i++;
        }
        
        // actual merge
        int idx = start;
        i = 0, j = 0;
        while(i < left_size && j < right_size) {
            if(left[i] <= right[j])
                nums[idx++] = left[i++];
            else 
                nums[idx++] = right[j++];
        }
        
        while(i < left_size) 
            nums[idx++] = left[i++];
        
        while(j < right_size)
            nums[idx++]  = right[j++];
    }
    void mergeSort(vector<int> &nums, int &pairs, int start, int end) {
        if(end <= start) return;
        int mid = start + (end - start)/2;
        mergeSort(nums, pairs, start, mid);
        mergeSort(nums, pairs, mid+1, end);
        
        merge(nums, pairs, start, mid, end);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int pairs = 0;
        mergeSort(nums, pairs, 0, n-1);
        return pairs;
    }
};