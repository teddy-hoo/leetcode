class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        map<char, int> m;
        int max = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++){
        	map<char, int>::iterator iter;
        	iter = m.find(s[i]);
        	if(iter == m.end()){
        		m[s[i]] = i;
        		len++;
        	}
        	else{
        		if(iter->second < start){
        			len++;
        		}
        		else{
        			int pos = iter->second;
        			max = max > len ? max : len;
        			len = i - pos;
        			start = i;
        		}
        		iter->second = i;
        	}
        }

        max = max > len ? max : len;
        return max;
    }
};
