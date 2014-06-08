class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	string result;
        if(strs.size() == 0){
        	return result;
        }
        int len = strs.size();
        int i, j;
        vector<char> prefix;
        vector<int> countPrefix;
        for(i = 0; i < len; ++i){
        	for(j = 0; j < strs[i].length(); ++j){
        		if(j < prefix.size()){
        			if(prefix[j] != strs[i][j]){
        				break;
        			}
        			else{
        				++countPrefix[j];
        			}
        		}
        		else{
        			prefix.push_back(strs[i][j]);
        			countPrefix.push_back(1);
        		}
        	}
        }
        if(countPrefix.size() > 0){
        	for(i = 0; countPrefix[i] == len; ++i);
        	if(i){
        		result = strs[0].substr(0, i);
        	}
        }        
        return result;
    }
};