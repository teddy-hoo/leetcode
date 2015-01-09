class Solution {
private:
	bool canBeBreak(string s, int index, unordered_set<string> dict){
		int len = s.size();
		unordered_set<string>::iterator iter;

		if(index == len){
			return true;
		}

		for(int i = index; i < len; i++){
			string sub = s.substr(index, i - index  + 1);
			iter = dict.find(sub);
			if(iter != dict.end()){
				if(canBeBreak(s, i + 1, dict)){
				    return true;
				}
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

  		return canBeBreak(s, 0, dict);
    }
};