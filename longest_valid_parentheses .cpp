class Solution {
private:
	void findValidParentheses(string s, vector<bool> &isValid){
		vector<int> indices;
		int len = s.size();
		for(int i = 0; i < len; i++){
			if(indices.size() == 0 ||
			   !(s[i] == ')' && s[indices.back()] == '(')){
				indices.push_back(i);
			}
			else{
				isValid[indices.back()] = true;
				isValid[i] = true;
				indices.pop_back();
			}
		}
	}
	int calMax(vector<bool> isValid){
		int max = 0;
		int cur = 0;
		int len = isValid.size();
		for(int i = 0; i < len; i++){
			if(isValid[i]){
				cur++;
			}
			else{
				max = cur > max ? cur : max;
				cur = 0;
			}
		}
		return max > cur ? max : cur;
	}
public:
    int longestValidParentheses(string s) {

		int len = s.size();
        if(s.size() <= 0){
        	return 0;
        }

        vector<bool> isValid(len, false);
        findValidParentheses(s, isValid);

        return calMax(isValid);
    }
};
