class Solution {
private:
	bool isPalindrome(string s, int begin, int len){
		int end = begin + len - 1;
		while(begin <= end){
			if(s[begin] != s[end]){
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
public:
    int minCut(string s) {
        
        int len = s.size();
        int minSplit = 1000;
        
        if(len <= 0){
        	return minSplit;
        }

        vector<int> mins(len);
        mins[0] = 0;

        for(int i = 1; i < len; i++){
        	int min = 1000;
        	for(int j = i; j > 0; j--){
        		if(mins[j - 1] < min && isPalindrome(s, j, i - j + 1)){
        			int curStep = mins[j - 1] + 1;
        			min = curStep > min ? min : curStep;
        		}
        	}
        	if(isPalindrome(s, 0, i + 1)){
        		min = 0;
        	}
        	mins[i] = min;
        }

        return mins[len - 1];
    }
};
