class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        if(*s == '\0' && *p == '\0'){
            return true;
        }
        
        if(*s == '\0' || *p == '\0'){
            return false;
        }
        
        while(*s != '\0' && *p != '\0'){
            if(*p == '*'){
                if(*(p + 1) != '*' && *s != *(p + 1)){
                    s++;
                    continue;
                }
                if(isMatch(s, p + 1)){
                    return true;
                }
                s++;
                if(*s == '\0'){
                    if(isMatch(s, p + 1)){
                        return true;
                    }
                }
            }
            else if(*p == '?' || *s == *p){
                s++;
                p++;
            }
            else{
                return false;
            }
        }
        
        if(*s != '\0' || *p != '\0'){
            return false;
        }
        
        return true;
    }
};