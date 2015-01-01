class Solution {
private:
    bool matching(const char *s, const char *p, int ps, int pp){
        while(s[ps] != '\0' && p[pp] != '\0'){
            if(p[pp + 1] == '*'){
                if(p[pp] == '.' || s[ps] == p[pp]){
                    if(matching(s, p, ps + 1, pp)){
                        return true;
                    }
                }
                pp++;
                pp++;
            }
            else if(p[pp] == s[ps] || p[pp] == '.'){
                pp++;
                ps++;
            }
            else{
                return false;
            }
        }
        if(s[ps] != '\0'){
            return false;
        }
        while(p[pp] != '\0'){
            if(p[pp + 1] == '*'){
                pp++;
                pp++;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool isMatch(const char *s, const char *p) {
        return matching(s, p, 0, 0);
    }
};