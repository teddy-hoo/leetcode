/**
 * Greedt algorithm
 * Time: O(n)
 * Space: O(1)
 * Author: Teddy
 * Date: 28-1-2015
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        
        if(n <= 0){
            return true;
        }
        
        int curStep = 1;
        int i;
        for(i = 0; i < n; i++){
            if(curStep <= 0){
                break;
            }
            curStep--;
            curStep = curStep > A[i] ? curStep : A[i];
        }
        
        return i == n;
    }
};