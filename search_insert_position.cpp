class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int indexa;
        int isfind = -1;
        for(indexa = 0; indexa < n; indexa ++){
            if(A[indexa] >= target){
                isfind = indexa;
                break;
            }
        }
        if(isfind == -1)
            return n;
        return isfind;
    }
};
