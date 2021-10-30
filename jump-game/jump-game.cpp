class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i = n-2, j = n-1;
        // Go from the right: idea no. 1
        for(i = n-2; i >= 0; i--){
            if(i + nums[i] >= j) j = i;
        }
        if(j==0) return true;
        return false;
        
        /*// My mathod accepted
        int n = nums.size(); i = n-2;
        int flag = 0,temp = 1;
        if (n==1) return true;
        while(i>=0){
            if(nums[i]>=temp) {i--;temp=1;f=1;}
            else {i--;temp++;f=0;}
        }
        if(f==1) return true;
        else return false;*/
    }
};