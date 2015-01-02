class Solution {
private:
	vector<int> genNext(char *needle){
		vector<int> next;
		next.push_back(0);
		int len = 1;
		for(; needle[len] != '\0'; len++){
			int pos = next[len - 1];
			if(needle[len] == needle[pos]){
				next.push_back(pos + 1);
			}
			else{
				next.push_back(0);
			}
		}
		len--;
		while(len > 0){
			next[len] = next[len - 1];
			len--;
		}
		next[0] = -1;
		return next;
	}
public:
    int strStr(char *haystack, char *needle) {
    	if(haystack[0] == '\0'){
    		return needle[0] == '\0' ? 0 : -1;
    	}
    	if(needle[0] == '\0'){
    		return 0;
    	}
    	vector<int> next = genNext(needle);
        for(int i = 0, j = 0; ; i++, j++){
        	if(haystack[i] == '\0'){
        		return needle[j] == '\0' ? i - j : -1;
        	}
        	if(needle[j] == '\0'){
        		return i - j;
        	}
        	if(haystack[i] != needle[j]){
        		int jump = next[j];
        		if(next[j] != -1){
        			j = jump - 1;
        			i--;
        		}
        		else{
        			j = -1;
        		}
        	}
        }
        return -1;
    }
};
