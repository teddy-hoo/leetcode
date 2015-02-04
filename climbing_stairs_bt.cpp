/**
 * Backtracking solution
 * Time: O(2^n)
 * Space: O(1)
 * Author: Teddy
 * Date: 04-02-2015
 */

/**
 * Time limit exceeded on LEETCODE.
 */

class Solution {
private:
	int climb(int n){
		if(n == 0){
			return 1;
		}

		int ways = 0;
		if(n >= 1){
			ways += climb(n - 1);
			if(n >= 2){
				ways += climb(n - 2);
			}
		}

		return ways;
	}
public:
    int climbStairs(int n) {

        if(n <= 0){
        	return 0;
        }

        return climb(n);
    }
};
