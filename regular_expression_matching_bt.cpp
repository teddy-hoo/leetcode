/**
 * Backtracking solution
 * Time:   depends pruning effect
 * Space:  O(1)
 * Author: Teddy
 * Date:   03-02-2015
 */

/**
 * Backtracking solution
 * recursion cases:
 * 	1. characters except '*':
 *		I. if next is '*':
 * 			a. recurse next directly
 *			b. if match, recurse next
 *		II. if not:
 *			a. if match, recurse next
 *			b. if not return false
 */

class Solution {
private:
	bool bt(const char *s, const char *p, int ps, int pp){

		if((s[ps] == '\0' && p[pp] == '\0')){
			return true;
		}

		if(p[pp] == '\0'){
			return false;
		}

		if(p[pp + 1] == '*'){
			if(bt(s, p, ps, pp + 2)){
				return true;
			}
			if(s[ps] != '\0' && (p[pp] == '.' || s[ps] == p[pp]) &&
			   bt(s, p, ps + 1, pp)){
				return true;
			}
		}
		else if(s[ps] != '\0' && (p[pp] == '.' || s[ps] == p[pp])){
			if(bt(s, p, ps + 1, pp + 1)){
				return true;
			}
		}

		return false;
	}
public:
    bool isMatch(const char *s, const char *p) {
        
        if(s == NULL || p == NULL){
        	return false;
        }

        return bt(s, p, 0, 0);

    }
};