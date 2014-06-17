class Solution {
private:
  int min(int x, int y){
    return x >= y ? y : x;
  }
public:
  int minPathSum(vector<vector<int> > &grid) {
    int row = grid.size();
    int column = grid[0].size();
    vector<vector<int> > result;
    vector<int> path;

    path.push_back(grid[0][0]);
    for(int i = 1; i < column; ++i){
      path.push_back(grid[0][i] + path[i - 1]);
    }
    result.push_back(path);
    path.clear();
    for(int i = 1; i < row; ++i){
      for(int j = 0; j < column; ++j){
        if(j - 1 >= 0){
          path.push_back(grid[i][j] + min(result[i - 1][j], path[j - 1]));
        }
        else{
          path.push_back(grid[i][j] + result[i - 1][j]);
        }
      }
      result.push_back(path);
      path.clear();
    }
    return result[row - 1][column - 1];
  }
};
