class Solution {
private:
	vector<vector<bool> > genEmptyVector(int len){
		vector<vector<bool> > flags;
		for(int i = 0; i < len; i++){
			vector<bool> row(len, false);
			flags.push_back(row);
		}
		return flags;
	}
	bool checkPre(vector<vector<bool> > flags, int row){
		if(row == 0){
			return true;
		}
		int pre = row - 1;
		for(int i = 0; i < row; i++){
			if(flags[i][pre]){
				return true;
			}
		}
		return false;
	}
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
  		int len = s.size();
  		if(len <= 0){
  			return true;
  		}

  		unordered_set<string>::iterator iter;
  		vector<vector<bool> > flags = genEmptyVector(len);

  		int begin = 0;
  		int j;
  		for(int i = 0; i < len; i++){
  			begin = -1;
  			for(int j = i; j < len; j++){
  				string sub = s.substr(i, j - i + 1);
  				iter = dict.find(sub);
  				if(iter == dict.end()){
  					continue;
  				}
  				if(checkPre(flags, i)){
  					if(j == len - 1){
  						return true;
  					}
  					if(begin == -1){
  						begin = j;
  					}
  					flags[i][j] = true;
  				}
  			}
  			if(begin != -1){
  				i = begin;
  			}
  		}

  		return false;
    }
};