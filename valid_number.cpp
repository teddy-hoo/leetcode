class Solution {
private:
    bool isdigit(const char c){
        return (c >= '0' && c <= '9');
    }
    bool isspace(const char c){
        return (c==' ' || c =='\t' || c=='\n' || c=='\r' || c=='\f' || c=='\v');
    }
    bool isSign(const char c){
        return (c == '-' || c == '+');
    }
public:
    bool isNumber(const char *s) {
        bool hasDot = false;
        bool hasE = false;
        while(*s != '\0' && isspace(*s)) {
            s++;
        }
        if(*s == '\0'){
            return false;
        }
        for(int i = 0; s[i] != '\0'; i++){
            if(isSign(s[i])){
                if(i != 0){
                    return false;
                }
            }
            else if(s[i] == 'e'){
                int a = i;
                if(isSign(s[i + 1])){
                    a++;
                }
                if(hasE || i == 0 || s[a + 1] == '\0' || !isdigit(s[a + 1]) || (s[i - 1] != '.' && !isdigit(s[i - 1]))){
                    return false;
                }
                i = a;
                hasE = true;
            }
            else if(s[i] == '.'){
                if(hasE || hasDot || ((i == 0 || !isdigit(s[i - 1])) && (s[i + 1] == '\0' || !isdigit(s[i + 1])))){
                    return false;
                }
                hasDot = true;
            }
            else if(isspace(s[i])){
                for(int j = i + 1; s[j] != '\0'; j++){
                    if(!isspace(s[j])){
                        return false;
                    }
                }
                return true;
            }
            else if(!isdigit(s[i])){
                return false;
            }
        }
        return true;
    }
};