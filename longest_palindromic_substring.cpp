class Solution {
private:
	int findPalindrome(string s, int begin, int end){
		int len = s.size();
		while(begin >= 0 && end < len && s[begin] == s[end]){
			begin--;
			end++;
		}
		return begin + 1;
	}
public:
    string longestPalindrome(string s) {
		int len = s.size();
		if(len <= 1){
			return s;
		}
		int max = 0;
		int begin = 0;
		for(int i = 0; i < len - 1; i++){
			int start = findPalindrome(s, i, i);
			int length = (i - start) * 2 + 1;
			if(length > max){
				max = length;
				begin = start;
			}
			start = findPalindrome(s, i, i + 1);
			length = (i - start) * 2 + 2;
			if(length > max){
				max = length;
				begin = start;
			}
		}
		return s.substr(begin, max);
    }
};
