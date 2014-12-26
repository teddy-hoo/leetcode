class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int max = 0;
        int start = 0;
		int locs[256];  
        memset(locs, -1, sizeof(int) * 256);

        for(int i = 0; i < s.size(); i++){
        	if(locs[s[i]] < 0{
        		locs[s[i]] = i;
        		len++;
        	}
        	else{
        		if(locs[s[i]] < start){
        			len++;
        		}
        		else{
        			max = max > len ? max : len;
        			len = i - locs[s[i]];
        			start = locs[s[i]] + 1;
        		}
        		locs[s[i]] = i;
        	}
        }

        max = max > len ? max : len;
        return max;
    }
};
