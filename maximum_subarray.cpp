class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(!A)
            return 0;
        int subsum = A[0];
        int maxsum = A[0];
        vector<int> sum;
        for(int i = 1; i < n; i++){
            if(subsum <= 0){
                if(subsum > maxsum)
                    maxsum = subsum;
                subsum = A[i];
            }
            else
                subsum += A[i];
            if(subsum > maxsum)
                maxsum = subsum;
        }
        return maxsum;
    }
};
