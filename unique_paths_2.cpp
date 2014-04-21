class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int* path = new int[row * col];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(j - 1 >= 0 && i - 1 >= 0)
                    path[col * i + j] = obstacleGrid[i][j] ? 0 : path[col * (i - 1) + j] + path[col * i + j - 1];
                else if(j - 1 >= 0)
                    path[col * i + j] = obstacleGrid[i][j] ? 0 : path[col * i + j - 1];
                else if(i - 1 >= 0)
                    path[col * i + j] = obstacleGrid[i][j] ? 0 : path[col * (i - 1) + j];
                else
                    path[0] = obstacleGrid[i][j] ? 0 : 1;
            }
        }
        return path[row * col - 1];
    }
};
