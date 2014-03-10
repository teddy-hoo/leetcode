class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *merge = new int[m + n];
        int i = 0;
        int j = 0;
        int index = 0;
        while(i < m && j < n){
            if(A[i] <= B[j])
                merge[index++] = A[i++];
            else
                merge[index++] = B[j++];
        }
        while(i < m)
            merge[index++] = A[i++];
        while(j < n)
            merge[index++] = B[j++];
        for(i = 0; i < m + n; i++)
            A[i] = merge[i];
    }
};
