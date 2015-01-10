class Solution {
private:
	void breakWord(string s, unordered_set<string> dict, int index, vector<string> &result, string &str){
		int len = s.size();
		unordered_set<string>::iterator iter;

		if(index == len){
			result.push_back(str);
		}

		for(int i = index; i < len; i++){
			string sub = s.substr(index, i - index + 1);
			iter = dict.find(sub);
			if(iter != dict.end()){
				breakWord(s, dict, i + 1, result, str + sub);
			}
		}
	}
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        int len = s.size();

        if(len <= 0){
        	return result;
        }

        string emptyStr;
        breakWord(s, dict, 0, result, emptyStr);

        return result;
    }
};