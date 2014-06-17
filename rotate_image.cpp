class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    int temp;
    int row = n >> 1;
    int column = n > 2 ?  (n >> 1) + n % 2 : n >> 1;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[n-1-j][i];
        matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        matrix[j][n-1-i] = temp;
      }
    }
  }
};
