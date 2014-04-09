class Solution {
public:
    int uniquePaths(int m, int n) {
        int* path = new int[m * n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j - 1 >= 0 && i - 1 >= 0)
                    path[n * i + j] = path[n * (i - 1) + j] + path[n * i + j - 1];
                else if(j - 1 >= 0)
                    path[n * i + j] = path[n * i + j - 1];
                else if(i - 1 >= 0)
                    path[n * i + j] = path[n * (i - 1) + j];
                else
                    path[0] = 1;
            }
        }
        return path[m * n - 1];
    }
};
