#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
    void findNextEmptyCell(vector<vector<char> > board, int &row, int &col){
        int rowNum = board.size();
        int colNum = board[0].size();
      
        while(row < rowNum){
            if(board[row][col] == '.'){
                return;
            }
            col++;
            row = col >= colNum ? row + 1 : row;
            col = col >= colNum ? 0 : col;
        }
    }
    bool isValid(vector<vector<char> > board, int row, int col, char value){
        int rowNum = board.size();
        int colNum = board[0].size();
        
        for(int i = 0; i < row; i++){
            if(board[i][col] == value){
                return false;
            }
        }
        
        for(int i = 0; i < col; i++){
            if(board[row][i] == value){
                return false;
            }
        }
        
        return true;
    }
    bool findSolution(vector<vector<char> > &board, int row, int col){
        int rowNum = board.size();
        int colNum = board[0].size();
        
        findNextEmptyCell(board, row, col);
        
        if(row >= rowNum){
            return true;
        }
        
        int max = colNum + '0';
        for(char cellValue = '1'; cellValue <= max; cellValue++){
            if(isValid(board, row, col, cellValue)){
                board[row][col] = cellValue;
                if(findSolution(board, row, col)){
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        
        if(board.size() == 0){
            return;
        }
        
        findSolution(board, 0, 0);

    }
};

int main(){

    vector<vector<char> > board;
    vector<char> row;
    row.push_back('.');
    row.push_back('.');
    row.push_back('9');
    row.push_back('7');
    row.push_back('4');
    row.push_back('8');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    board.push_back(row);
    row.clear();
    row.push_back('7');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    board.push_back(row);
    row.clear();
    row.push_back('.');
    row.push_back('2');
    row.push_back('.');
    row.push_back('1');
    row.push_back('.');
    row.push_back('9');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    board.push_back(row);
    row.clear();
    row.push_back('.');
    row.push_back('.');
    row.push_back('7');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('2');
    row.push_back('4');
    row.push_back('.');
    board.push_back(row);
    row.clear();
    row.push_back('.');
    row.push_back('6');
    row.push_back('4');
    row.push_back('.');
    row.push_back('1');
    row.push_back('.');
    row.push_back('5');
    row.push_back('9');
    row.push_back('.');
    board.push_back(row);
    row.clear();
    row.push_back('.');
    row.push_back('9');
    row.push_back('8');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('3');
    row.push_back('.');
    board.push_back(row);
    row.clear();
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('8');
    row.push_back('.');
    row.push_back('3');
    row.push_back('.');
    row.push_back('2');
    row.push_back('.');
    board.push_back(row);
    row.clear();
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('6');
    board.push_back(row);
    row.clear();
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('.');
    row.push_back('2');
    row.push_back('7');
    row.push_back('5');
    row.push_back('9');
    row.push_back('.');
    board.push_back(row);
    row.clear();

    Solution sol;
    sol.solveSudoku(board);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}