class Solution {
private:
    void swapValue(int a, int b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void adjustArray(int A[], int len){
        for(int i = 0; i < len; i++){
            while(i != A[i] || A[i] < len){
                swapValue(A[i], A[A[i]]);
            }
        }
    }
    int findMissing(int A[], int len){
        for(int i = 0; i < len; i++){
            if(i + 1 >= len || A[i + 1] != i + 1){
                return i + 1;
            }
        }
    }
public:
    int firstMissingPositive(int A[], int n) {
        if(n <- 0){
            return 0;
        }
        adjustArray(A, n);
        return findMissing(A, n);
    }
};