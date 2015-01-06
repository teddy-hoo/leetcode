class Solution {
private:
    bool findSolution(vector<vector<char> > &board, int row, int col, 
        bool existRow[100][100], bool existCol[100][100], bool existArea[100][100]){
        int rowNum = board.size();
        int colNum = board[0].size();

        if(row >= rowNum){
            return true;
        }

        if(col >= colNum){
            return findSolution(board, row + 1, 0, existRow, existCol, existArea);
        }

        if(board[row][col] != '.'){
            return findSolution(board, row, col + 1, existRow, existCol, existArea);
        }
        
        int area = (row / 3) * 3 + col / 3;
        for(int v = 0; v < rowNum; v++){
            if(existRow[row][v] || existCol[col][v] || existArea[area][v]){
                continue;
            }
            existRow[row][v] = true;
            existCol[col][v] = true;
            existArea[area][v] = true;
            board[row][col] = v + '1';
            if(findSolution(board, row, col + 1, existRow, existCol, existArea)){
                return true;
            }
            board[row][col] = '.';
            existRow[row][v] = false;
            existCol[col][v] = false;
            existArea[area][v] = false;
        }

        return false;
    }
    bool initExist(vector<vector<char> > board, bool existRow[100][100],
        bool existCol[100][100], bool existArea[100][100]){
        int rowNum = board.size();
        int colNum = board[0].size();

        for(int i = 0; i < rowNum; i++){
            for(int j = 0; j < colNum; j++){
                if(board[i][j] == '.'){
                    continue;
                }

                int value = board[i][j] - '1';
                int area = (i / 3) * 3 + j / 3;
                if(existRow[i][value] ||
                    existCol[j][value] ||
                    existArea[area][value]){
                    return false;
                }
                existRow[i][value] = true;
                existCol[j][value] = true;
                existArea[area][value] = true;
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        
        if(board.size() == 0){
            return;
        }

        bool existRow[100][100];
        bool existCol[100][100];
        bool existArea[100][100];
        memset(existRow, false, sizeof(existRow));
        memset(existCol, false, sizeof(existCol));
        memset(existArea, false, sizeof(existArea));
        if(!initExist(board, existRow, existCol, existArea)){
            return;
        }
        
        findSolution(board, 0, 0, existRow, existCol, existArea);

    }
};
