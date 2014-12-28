class Solution {
private:
    void swapValue(int a, int b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void adjustArray(int A[], int len){
        for(int i = 0; i < len; i++){
            while(A[i] > 0 && i + 1 != A[i] && A[i] < len && A[i] != A[A[i] - 1]){
                swapValue(A[i], A[A[i] - 1]);
            }
        }
    }
    int findMissing(int A[], int len){
        for(int i = 0; i < len; i++){
        	if(A[i] != i + 1){
        		return i + 1;
        	}
        	if(i + 1 >= len){
        		return len + 1;
        	}
        }
    }
public:
    int firstMissingPositive(int A[], int n) {
        if(n <= 0){
            return 1;
        }
        adjustArray(A, n);
        return findMissing(A, n);
    }
};
