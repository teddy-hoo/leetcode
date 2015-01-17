class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n <= 0){
            return false;
        }

        int begin = 0;
        int end = n - 1;
        while(begin <= end){
            int middle = (begin + end) / 2;
            if(A[middle] == target){
                return true;
            }
            while(begin != middle && A[middle] == A[middle - 1]){
                middle--;
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

        return false;
    }
};
