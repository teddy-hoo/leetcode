class Solution {
private:
	bool isPalindrome(string s){
		int begin = 0;
		int end = s.size() - 1;
		while(begin <= end){
			if(s[begin] != s[end]){
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
	void findPartitions(string s, int cur, vector<string> &result, vector<vector<string> > &results){
		int len = s.size();
		if(cur == len){
			results.push_back(result);
			return;
		}
		for(int i = cur; i < len; i++){
			string sub = s.substr(cur, i - cur + 1);
			if(isPalindrome(sub)){
				result.push_back(sub);
				findPartitions(s, i + 1, result, results);
				result.pop_back();
			}
		}
	}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > results;
        if(s.size() <= 0){
        	return results;
        }
        vector<string> result;
        findPartitions(s, 0, result, results);
        return results;
    }
};