class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        vector<vector<bool> > row(9, vector<bool> (9, false));
       	vector<vector<bool> > col(9, vector<bool> (9, false));
       	vector<vector<bool> > blo(9, vector<bool> (9, false));

       	for(int i = 0; i < 9; i++){
       		for(int j = 0; j < 9; j++){
       		    if(board[i][j] == '.'){
       		        continue;
       		    }
       			int bi = i / 3 * 3 + j / 3;
       			int val = board[i][j] - '1';
       			if(row[i][val] || col[j][val] || blo[bi][val]){
       				return false;
       			}
       			row[i][val] = true;
       			col[j][val] = true;
       			blo[bi][val] = true;
       		}
       	}

       	return true;
    }
};