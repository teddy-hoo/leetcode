class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        bool star = false;
        const char *s1, *p1;
        while( *s && (*p || star) ){
            if (*p=='?' || *s == *p){
                s++; p++;
            }else if (*p=='*'){
                star = true;
                p++;
                if (*p=='\0') return true;
                s1 = s;
                p1 = p;
            }else{
                if (star==false) return false;
                p = p1;
                s = ++s1; 
            }
        }
        if (*s=='\0') {
            while (*p=='*') p++;
            if (*p=='\0') return true;
        }
        return false;
    }
};