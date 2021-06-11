// TC - O(N)
// SC - O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int oddZeros = 0, oddOnes = 0, evenZeros = 0, evenOnes = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(i%2) oddOnes++;
                else evenOnes++;
            }
            else {
                if(i%2) oddZeros++;
                else evenZeros++;
            }
        }
        
        // If i need all ones at odd and all zeros at even 1010...
        // without shift ==> oddZeros + evenOnes;
        //evenZeros + oddOnes;
        // ans = min( ans, min(oddZeros + evenOnes, evenZeros + oddOnes));
        
        int ans = INT_MAX;
        ans = min(ans, min(oddZeros + evenOnes, evenZeros + oddOnes));
        for(int i = 0; i < n; i++) {
            // now make the shift and update oddZeros, evenOnes, evenZeros, oddOnes
            if(s[i] == '0') {
                evenZeros--;
                swap(oddZeros, evenZeros);
                swap(oddOnes, evenOnes);
                if((n-1)%2 == 0) evenZeros++;
                else oddZeros++;
            }
            else {
                evenOnes--;
                swap(oddZeros, evenZeros);
                swap(oddOnes, evenOnes);
                if((n-1)%2 == 0) evenOnes++;
                else oddOnes++;
            }
            ans = min(ans, min(oddZeros + evenOnes, evenZeros + oddOnes));
        }
        return ans;
    }
};