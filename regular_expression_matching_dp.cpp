/**
 * Dynamic programming solution
 * Time: O(nm)
 * Space: O(nm)
 * Author: Teddy
 * Date: 03-02-2015
 */

/**
 * b 0 0 0 1
 * * 1 1 1 0
 * a 0 0 0 0
 * * 1 1 1 0
 * c 1 1 1 0
 *   c c c b
 */


/**
 * matachTable  m
 * m[i][j] = | 1 if p[i] == '.' && m[i - 1][j - 1]
 *           | 1 if p[i] == s[j] && m[i - 1][j - 1]
 *           | 1 if p[i] == '*' && m[i - 1][j]
 *           | 1 if p[i] == '*' && m[i - 2][j]
 *           | 0 otherwise
 */


class Solution {
private:
    int getLen(const char *s){
        int len = 0;
        while(*s != '\0'){
            len++;
            s++;
        }
        return len;
    }
public:
    bool isMatch(const char *s, const char *p) {

        if(s == NULL && p == NULL){
            return false;
        }

        int lens = getLen(s);
        int lenp = getLen(p);

        vector<vector<int> > m(lenp + 1, vector<int> (lens + 1, false));
        m[0][0] = true;
        for(int i = 1; i <= lenp; i++){
            if(p[i - 1] == '*' && m[i - 2][0] == true){
                m[i][0] = true;
            }
        }

        for(int i = 1; i <= lenp; i++){
            for(int j = 1; j <= lens; j++){
                if(p[i - 1] == '*'){
                    m[i][j] = m[i - 1][j] || m[i - 2][j];
                }
                else if(p[i - 1] == '.' || p[i - 1] == s[j - 1]){
                    m[i][j] = m[i - 1][j - 1] ||
                              (i < lenp && p[i] == '*' && m[i][j - 1]);
                }
            }
        }

        return m[lenp][lens];

    }
};