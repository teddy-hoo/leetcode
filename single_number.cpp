class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n <= 0){
            return -1;
        }
        
        int xorResult = A[0];
        
        for(int i = 1; i < n; i++){
            xorResult ^= A[i];
        }
        
        return xorResult;
    }
};
