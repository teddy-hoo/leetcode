class Solution {
public:
    int search(int A[], int n, int target) {
        if(n <= 0){
            return -1;
        }

        int begin = 0;
        int end = n - 1;
        while(begin <= end){
            int middle = (begin + end) / 2;
            if(A[middle] == target){
                return middle;
            }
            if(begin == middle || A[begin] < A[middle]){
                if(A[middle] < target || A[begin] > target){
                    begin = middle + 1;
                }
                else{
                    end = middle - 1;
                }
            }
            else{
                if(target > A[end] || target < A[middle]){
                    end = middle - 1;
                }
                else{
                    begin = middle + 1;
                }
            }
        }

        return -1;
    }
};
