/**
 * Binary search solution
 * Time:   O(logn)
 * Space:  O(1)
 * Author: Teddy
 * Date:   05-02-2015
 */

/**
 * Main function
 * * * * * * * * *
 * array:  5 7 7 8 8 10
 * target: 8
 * 
 * begin:  5  8  
 * end:    10 10 
 * middle: 7  8  
 *
 * middle < target: begin = middle + 1
 * middle > target: end = middle - 1
 * 
 * middle = target: findFirst(begin, middle), findLast(middle, end)
 *
 */

/**
 * findFirst function
 * * * * * * * * *
 * part: 8 8
 * 
 * begin:  8
 * end:    8
 * middle: 8
 *
 * middle = target: end = middle - 1
 * middle < target: begin = middle + 1 
 */

/**
 * findLast function
 * * * * * * * * *
 * part: 8 10
 * 
 * begin:  8
 * end:    10
 * middle: 8
 *
 * middle = target: begin = middle + 1
 * middle > target: end = middle - 1 
 */


class Solution {
private:
    int findFirst(int A[], int begin, int end, int target){
        
        while(begin <= end){
            int middle = begin + (end - begin) / 2;
            if(A[middle] == target){
                end = middle - 1;
            }
            else{
                begin = begin + 1;
            }
        }
        
        return end + 1;
    }
    int findLast(int A[], int begin, int end, int target){
        
        while(begin <= end){
            int middle = begin + (end - begin) / 2;
            if(A[middle] == target){
                begin = middle + 1;
            }
            else{
                end = middle - 1;
            }
        }
        
        return begin - 1;
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        int start = -1;
        int over = -1;
        
        int begin = 0;
        int end = n - 1;
        while(begin <= end){
            int middle = begin + (end - begin) / 2;
            if(A[middle] == target){
                start = findFirst(A, begin, middle, target);
                over = findLast(A, middle, end, target);
                break;
            }
            else if(A[middle] < target){
                begin = middle + 1;
            }
            else{
                end = middle - 1;
            }
        }
        
        return {start, over};
    }
};