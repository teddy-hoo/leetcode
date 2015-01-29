/**
 * Dynamic progromming algorithm
 * Time: O(n^2)
 * Space: O(n^2)
 * Author: Teddy
 * Date: 29-01-2015
 */

/**
 * a 6 0 0 3 0 1
 * b 0 4 0 0 1
 * a 0 0 2 1
 * a 3 0 1
 * b 2 1
 * a 1
 *   a b a a b a
 */

/**
 * longest[i][j]:
 *               s[i] != s[j]: 0
 *				 s[i] == s[j]: 2 + longest[i - 1][j + 1]
 */

class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.size();

        if(len <= 0){
        	return "";
        }

        int end = 0;
        int max = 1;
        vector<vector<int> > longest(len, vector<int> (len, 0));

        for(int i = 0; i < len; i++){
        	for(int j = 0; j < i; j++){
        		if(s[i] == s[j]){
        			int newLen = 2 + longest[i - 1][j + 1];
        			longest[i][j] = newLen;
        			if(newLen > max){
        				max = newLen;
        				end = i;
        			}
        		}
        	}
        	longest[i][i] = 1;
        }

        return s.substr(end - max + 1, max);

    }
};