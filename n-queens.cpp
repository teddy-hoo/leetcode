class Solution {
private:
	vector<vector<bool> > createChessboard(int n){
		vector<vector<bool> > chessboard;
		for(int i = 0; i < n; i++){
			vector<bool> row(n, false);
			chessboard.push_back(row);
		}
		return chessboard;
	}
	bool validate(vector<vector<bool> > chessboard, int x, int y){
		int len = chessboard[0].size();
		for(int i = 0; i < x; i++){
			if(chessboard[i][y]){
				return false;
			}
		}
		for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
			if(chessboard[i][j]){
				return false;
			}
		}
		for(int i = x - 1, j = y + 1; i >= 0 && j < len; i--, j++){
			if(chessboard[i][j]){
				return false;
			}
		}
		return true;
	}
	vector<string> genResult(vector<vector<bool> > chessboard){
		vector<string> result;
		int len = chessboard.size();
		for(int i = 0; i < len; i++){
			string row = "";
			for(int j = 0; j < len; j++){
				char chess = chessboard[i][j] ? 'Q' : '.';
				row += chess;
			}
			result.push_back(row);
		}
		return result;
	}
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > results;
        if(n <= 0){
        	return results;
        }
        vector<vector<bool> > chessboard = createChessboard(n);
        stack<vector<int> > positions;
        int x = 0;
        int y = 0;
        int queens = n;
        while((x < n && y < n) || !positions.empty()){
        	while(x < n && y < n && !validate(chessboard, x, y)){
        		y++;
        	}
        	if(y >= n || x >= n){
        		if(queens == 0){
        			results.push_back(genResult(chessboard));
        		}
        		vector<int> xy = positions.top();
        		positions.pop();
        		x = xy[0];
        		y = xy[1];
        		chessboard[x][y] = false;
        		y++;
        		queens++;
        	}
        	else{
        		vector<int> xy;
        		queens--;
        		chessboard[x][y] = true;
        		xy.push_back(x);
        		xy.push_back(y);
        		positions.push(xy);
        		x += 1;
        		y = 0;
        	}
        }
        return results;
    }
};