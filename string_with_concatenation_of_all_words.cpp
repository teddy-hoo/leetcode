class Solution {
private:
	map<char, string> genDict(vector<string> l){
		int len = l.size();
		map<char, string> dict;
		for(int i = 0; i < len; i++){
			dict[l[i][0]] = l[i];
		}
		return dict;
	}
	map<char, int> genSymbol(vector<string> l){
		int len = l.size();
		map<char, int> symbol;
		for(int i = 0; i < len; i++){
			symbol[l[i][0]] = -1;
		}
		return symbol;
	}
	bool isDistinct(string word, string s, int index){
		int len = word.size();
		int i = 0;
		while(i < len){
			if(word[i] != s[index + i]){
				return false;
			}
			i++;
		}
		return true;
	}
	void clearSymbol(map<char, int> &symbol, int pos){
		map<char, int>::iterator iter;
		for(iter = symbol.begin(); iter != symbol.end(); iter++){
			if(pos == - 1 || iter->second <= pos){
				iter->second = -1;
			}
		}
	}
	bool checkFull(map<char, int> symbol){
		map<char, int>::iterator iter;
		for(iter = symbol.begin(); iter != symbol.end(); iter++){
			if(iter->second < 0){
				return false;
			}
		}
		return true;
	}
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        int lens = S.size();
        int lenl = L.size();
        if(lens <= 0 || lenl <= 0 || L[0].size() <= 0){
        	return result;
        }
        map<char, string> dict = genDict(L);
        map<char, string>::iterator iterD;
        map<char, int> symbol = genSymbol(L);
        for(int i = 0; i < lens; i++){
        	int cur = i;
        	iterD = dict.find(S[cur]);
        	while(iterD != dict.end()){
        		if(!isDistinct(iterD->second, S, cur)){
        			break;
        		}
        		if(symbol[S[cur]] != -1){
        			i = symbol[S[cur]] + iterD->second.size();
        			clearSymbol(symbol, symbol[S[cur]]);
        		}
        		symbol[S[cur]] = cur;
        		if(checkFull(symbol)){
        			result.push_back(i);
        		}
        		cur = cur + iterD->second.size();
        		if(cur >= lens){
        			break;
        		}
        		iterD = dict.find(S[cur]);
        	}
        	clearSymbol(symbol, -1);
        }
        return result;
    }
};
