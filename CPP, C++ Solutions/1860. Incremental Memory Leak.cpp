// TC - O(n) -> n_max = 1e5
// SC - O(1)
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 0;
        while(++i) {
            if(memory1 < i && memory2 < i) 
                break;
            
            if(memory1 >= memory2) 
                memory1 -= i;
            else memory2 -= i;
        }
        return {i, memory1, memory2};
    }
};