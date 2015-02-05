/**
 * Dynamic programming solution
 * Time:   O(mn)
 * Space:  O(mn)
 * Author: Teddy
 * Date:   05-02-2015
 */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        if(row <= 0 || col <= 0){
            return 0;
        }
        
        vector<vector<int> > sums(row, vector<int> (col, 0));
        
        sums[0][0] = grid[0][0];
        
        // init first row
        for(int i = 1; i < col; i++){
            sums[0][i] = grid[0][i] + sums[0][i - 1];
        }
        
        // init first col
        for(int i = 1; i < row; i++){
            sums[i][0] = grid[i][0] + sums[i - 1][0];
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                int min = sums[i - 1][j] < sums[i][j - 1] ? sums[i - 1][j] : sums[i][j - 1];
                sums[i][j] = grid[i][j] + min;
            }
        }
        
        return sums[row - 1][col - 1];
    }
};