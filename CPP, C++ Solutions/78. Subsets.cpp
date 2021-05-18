/*************************Method1***********************************
class Solution {
public:
    vector<vector<int>> f(vector<int> &nums, int i, int end) {
        // Base Case
        if(i == end) {
            return {{}, {nums[end]}};
        }
        
        // Recursive Step
        // Get C2 & C1
        // Get C2
        vector<vector<int>> c2 = f(nums, i+1, end);
        
        // Get C1
        // c2 = {{2}, {3}. {}, {2, 3}} // nums[i] = 1
        // c1 = {{2, 1}, {3, 1}, {1}, {2, 3, 1}}
        
    /*******M1******
        vector<vector<int>> c1;
        for(auto &elt: c2) {
            // Pushing a vector
            c1.push_back(elt);
            // In the last vector inserted push first element
            c1[c1.size()-1].push_back(nums[i]);
        }
    /******************
    
    /********M2*********
        vector<vector<int>> c1 = c2;
        
        for(int j = 0; j < c1.size(); j++) 
            c1[j].push_back(nums[i]);
    /********************
    
        // Combine them 
        vector<vector<int>> res = c2;
        
        for(int j = 0; j < c1.size(); j++) 
            res.push_back(c1[j]);
        
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return f(nums, 0, nums.size()-1);
    }
};
****************************************************************/

/************************Method2*******************************/

class Solution {
public:
    void f(vector<int> &nums, int i, int end, vector<int> contri, vector<vector<int>> &res) {
        if(i == end) {
            res.push_back(contri);
            contri.push_back(nums[end]);
            res.push_back(contri);
            return;
        }
        // Recursive Step
        // C2
        f(nums, i+1, end, contri, res);
        
        // C1
        // Contribution at this step is nums[i]
        contri.push_back(nums[i]);
        f(nums, i+1, end, contri, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        // Implicit return
        f(nums, 0, nums.size()-1, {}, res);
        
        return res;
    }
};
