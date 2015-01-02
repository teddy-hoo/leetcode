class Solution {
private:
	void genWords(vector<string> l, map<string, vecgto){
		map<string, vector<int> > words;
		map<string, vector<int> >::iterator iter;
		int num = l.size();
		for(int i = 0; i < num; i++){
			iter = words.find(l[i]);
			if(iter == words.end()){
				vector<int> indices;
				indices.push_back(i);
				words[l[i]] = indices;
			}
			else{
				iter->second.push_back(i);
			}
		}
		return words;
	}
	vector<vector<int> > genPos(string s, map<string, vector<int> > words, int step){
		int len = s.size() - step;
		map<string, vector<int> >::iterator iter;
		vector<vector<int> > wordPos;
		vector<int> emptyVector;
		for(int i = 0; i <= len; i++){
			string word = s.substr(i, step);
			iter = words.find(word);
			if(iter != words.end()){
				wordPos.push_back(iter->second);
			}
			else{
				wordPos.push_back(emptyVector);
			}
		}
		return wordPos;
	}
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		map<string,vector<int> > words;
		vector<vector<int> > wordPos;
		vector<int> result;

		int wordNum = L.size();
		int wordLen = L[0].size();

		words = genWords(L);
		wordPos = genPos(S, words, wordLen);
		words.clear();

		bool symbol[500];
		memset(symbol, false, sizeof(bool) * 500);
		int maxLen = wordLen * wordNum;
		int maxIndex = S.size() - maxLen;
		for(int i = 0; i <= maxIndex; i++)
		{
			int j = 0;
			while(j < maxLen)
			{
				vector<int> pos = wordPos[i + j];
				if(pos.size() <= 0){
					break;
				}
				int k = 0;
				for(; k < pos.size(); k++){
					if(!symbol[pos[k]]){
						symbol[pos[k]] = true;
						break;
					}
				}
				if(k == pos.size()){
					break;
				}
				j += wordLen;
			}
			if(j == maxLen){
				result.push_back(i);
			}
			memset(symbol, false, sizeof(bool) * 500);
		}
		return result;
	}
};