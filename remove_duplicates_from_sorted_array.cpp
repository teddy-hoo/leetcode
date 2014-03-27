class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0)
            return 0;
        int indexa = 1;
        int indexn = 0;
        for(; indexa < n; indexa++){
            if(A[indexa] == A[indexn])
                continue;
            else
                A[++indexn] = A[indexa];
        }
        return indexn + 1;
    }
};
