class Solution {
public:
    void sortColors(int A[], int n) {
        map<int, int> m;
        m[0] = 0;
        m[1] = 0;
        m[2] = 0;
        int i =0;
        for(; i < n; i++)
            m[A[i]]++;
        for(i = 0; i < n; i++){
            if(i < m[0])
                A[i] = 0;
            else if(i < (m[0] + m[1]))
                A[i] = 1;
            else
                A[i] = 2;
        }
    }
};
