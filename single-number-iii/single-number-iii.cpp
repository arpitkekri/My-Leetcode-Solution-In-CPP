class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int AxorB = 0;
        for(int i = 0; i < nums.size(); i++)
            AxorB ^= nums[i];
        
        int pos = 0;
        for(; pos < 32; pos++)
            if(AxorB & (1 << pos)) 
                break;
        
        int A = 0, B = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] & (1 << pos)) 
                A ^= nums[i];
            else B ^= nums[i];
        return {A, B};
    }
};