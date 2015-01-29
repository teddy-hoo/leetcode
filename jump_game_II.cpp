/**
 * Greedy algorithm
 * Time:   O(n)
 * Space:  O(1)
 * Author: Teddy
 * Date:   29-01-2015
 */

/**
 * compare current step count with left distance.
 * 7 1 9 2 3 9 1 2 3 4 5 6 2 1 2 
 */


class Solution {
public:
    int jump(int A[], int n) {
        
        if(n <= 0){
            return 0;
        }      
        
        int steps = 1;
        int currentStep = A[0];
        int maxSteps = 0;
        int maxIndex = 0;
        bool reached = false;
        for(int i = 1; i < n; i++){
            currentStep--;
            if(currentStep >= n - i - 1){
                reached = true;
                break;
            }
            // use >= operator will save a little time, 
            // which will select the last one when there are multiple equal
            // steps
            if(A[i] + i >= maxSteps){
                maxSteps = A[i] + i;
                maxIndex = i;
            }
            if(currentStep == 0){
                i = maxIndex;
                currentStep = A[maxIndex];
                steps++;
            }
        }
        
        return reached ? steps : 0;
    }
};