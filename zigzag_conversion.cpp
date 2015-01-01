class Solution {
private:
	void addHead(string s, int rows, string &result){
		int len = s.size();
		int step = 2 * rows - 2;
		for(int i = 0; i < len; i += step){
			result += s[i];
		}
	}
	void addBody(string s, int rows, string &result){
		int len = s.size();
		int step = 2 * rows - 2;
		for(int i = 1; i < rows - 1; i++){
			int another = step - 2 * i;
			for(int j = i; j < len; j += step){
				result += s[j];
				if(j + another < len){
					result += s[j + another];
				}
			}
		}
	}
	void addTail(string s, int rows, string &result){
		int len = s.size();
		int step = 2 * rows - 2;
		for(int i = rows - 1; i < len; i += step){
			result += s[i];
		}
	}
public:
    string convert(string s, int nRows) {
        string result;
        if(s.size() <= nRows || nRows <= 1){
        	return s;
        }
        addHead(s, nRows, result);
        addBody(s, nRows, result);
        addTail(s, nRows, result);
        return result;
    }
};