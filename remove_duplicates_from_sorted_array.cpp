/**
 * Naive solution
 * Time:   O(n)
 * Space:  O(1)
 * Author: Teddy
 * Date:   04-02-2015
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {

        int real = 0;
        
        for(int i = 0; i < n; i++){
            while(i < n - 1 && A[i] == A[i + 1]){
                i++;
            }
            A[real++] = A[i];
        }
        
        return real;
    }
};