class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid;
        
        if(nums.size() == 1) return 0;
        
        while(lo < hi)
        {
            mid = lo + (hi-lo)/2;
            
            if(nums[mid]-nums[mid+1] > 0)
                hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};