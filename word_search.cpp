class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        stack<vector<int>> store;
        if(board.size() <= 0)
            return false;
        if(word.size() <= 0)
            return true;
        vector<int> cur;
        vector<int> another;
        int cou;
        for(int indexv = 0; indexv < board.size(); indexv++){
		    for(int indexh = 0; indexh < board[indexv].size(); indexh++){
			    if(word[0] == board[indexv][indexh]){
			        another.clear();
				    another.push_back(0);
				    another.push_back(indexv);
				    another.push_back(indexh);
				    another.push_back(1);
				    store.push(another);
			    }
		    }
	    }
        while(!store.empty()){
    		cou = 0;
    		cur = store.top();
    		store.pop();
    		if(cur[3] == 1){
    		    cur[3] = 0;
    		    store.push(cur);
    		    board[cur[1]][cur[2]] = 0;
    		}
    		else{
    		    board[cur[1]][cur[2]] = word[cur[0]];
    		    continue;
    		}
    		if(cur[0] == word.size() - 1)
    			return true;
    		if(cur[1] - 1 >= 0 && board[cur[1] - 1][cur[2]] == word[cur[0] + 1]){
    			another.clear();
    			another.push_back(cur[0] + 1);
    			another.push_back(cur[1] - 1);
    			another.push_back(cur[2]);
    			another.push_back(1);
    			store.push(another);
    			cou++;
    		}
    		if(cur[2] - 1 >= 0 && board[cur[1]][cur[2] - 1] == word[cur[0] + 1]){
    			another.clear();
    			another.push_back(cur[0] + 1);
    			another.push_back(cur[1]);
    			another.push_back(cur[2] - 1);
    			another.push_back(1);
    			store.push(another);
    			cou++;
    		}
    		if(cur[1] + 1 < board.size() && board[cur[1] + 1][cur[2]] == word[cur[0] + 1]){
    			another.clear();
    			another.push_back(cur[0] + 1);
    			another.push_back(cur[1] + 1);
    			another.push_back(cur[2]);
    			another.push_back(1);
    			store.push(another);
    			cou++;
    		}
    		if(cur[2] + 1 < board[cur[1]].size() && board[cur[1]][cur[2] + 1] == word[cur[0] + 1]){
    			another.clear();
    			another.push_back(cur[0] + 1);
    			another.push_back(cur[1]);
    			another.push_back(cur[2] + 1);
    			another.push_back(1);
    			store.push(another);
    			cou++;
    		}
    		if(cou == 0){
    			board[cur[1]][cur[2]] = word[cur[0]];
    			store.pop();
    		}
    	}
        return false;
    }
};
