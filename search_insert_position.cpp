class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        
        if(n <= 0){
            return 0;
        }

        int begin = 0;
        int end = n - 1;
        while(begin <= end){
            int middle = (begin + end) / 2;
            if(A[middle] == target){
                return middle;
            }
            else if(A[middle] < target){
                begin = middle + 1;
            }
            else{
                end = middle - 1;
            }
        }
        return begin;
    }
};
