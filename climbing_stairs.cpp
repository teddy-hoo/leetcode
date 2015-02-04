/**
 * Dynamic programming sulotion
 * Time:   O(n)
 * Space:  O(n)
 * Author: Teddy
 * Date:   04-02-2015
 */

class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 0 || n == 1 || n == 2){
            return n;
        }
        
        vector<int> steps(n);
        steps[0] = 1;
        steps[1] = 2;
        for(int i = 2; i < n; i++){
            steps[i] = steps[i - 1] + steps[i - 2];
        }

        return steps[n - 1];
    }
};
