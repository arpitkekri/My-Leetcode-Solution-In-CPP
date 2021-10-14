class Solution {
public:
    bool isDivide(int n, int count, set<int> &squres) {
        if(count == 1)
            return squres.find(n) != squres.end();
        
        for(auto &sq: squres) {
            if(isDivide(n - sq, count-1, squres))
                return true;
        }
        return false;
    }
    
    int numSquares(int n) {
        set<int> squres;
        for(int i = 1; i*i <= n; i++)
            squres.insert(i*i);
        
        int count;
        // for(count = 1; count <= n; count++) {
        //     if(isDivide(n, count, squres))
        //         return count;
        // }
        
        
        // By Lagrange's four-square theorem -> 
        // every natural number can be represented as the sum of four integer squares
        for(count = 1; count <= 4; count++) {
            if(isDivide(n, count, squres))
                return count;
        }
        return count;
    }
};