class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n <= 0){
            return -1;
        }
        
        int max = A[0];
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(cur + A[i] < 0){
                max = A[i] > max ? A[i] : max;
                cur = 0;
            }
            else{
                cur += A[i];
                max = cur > max ? cur : max;
            }
        }
        
        return max;
    }
};
