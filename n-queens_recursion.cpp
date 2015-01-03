class Solution {
private:
	bool validate(int row, int col, int n, vector<int> solution){
		for(int i = 0; i < row; i++) {
		    if (col == solution[i] || 
		        abs(col - solution[i]) == abs(row - i)) {
		            return false;
		    } 
		}
		return true;
	}
	vector<string> genResult(vector<int> solution){
		vector<string> result;
		int len = solution.size();
		for(int i = 0; i < len; i++){
			string row = "";
			for(int j = 0; j < len; j++){
				char chess = j == solution[i] ? 'Q' : '.';
				row += chess;
			}
			result.push_back(row);
		}
		return result;
	}
	void recursion(int curRow, int rowNum, vector<int> &solution, vector<vector<string> > &results){
		if(curRow == rowNum){
			results.push_back(genResult(solution));
		}
		else{
			for(int col = 0; col < rowNum; col++){
				if(validate(curRow, col, rowNum, solution)){
					solution[curRow] = col;
					recursion(curRow + 1, rowNum, solution, results);
				}
			}
		}
	}
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > results;
        if(n <= 0){
        	return results;
        }
        vector<int> solution(n);
        recursion(0, n, solution, results);
        return results;
    }
};