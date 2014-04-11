class Solution {
public:
    int search(int A[], int n, int target) {
        bool flag = false;
        int i = 0;;
        int count = 0;
        if(A[0] > target)
            i = n - 1;
        for(i = 0; A[i] != target && count < n; count++){
            i = flag? i - 1: i + 1;
        }
        return count == n? -1 : i;
    }
};
