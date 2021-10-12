/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int verdict = guess(mid);
            if(verdict == 0) return mid;
            else if(verdict == -1) hi = mid;
            else lo = mid+1;
        }
        return -1;
    }
};