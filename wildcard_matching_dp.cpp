class Solution {
private:
    int getLen(const char *s){
        
        int len = 0;
        
        while(*s != '\0'){
            s++;
            len++;
        }
        
        return len;
    
    }
    vector<vector<bool> > genEmtpyVector(int row, int col){
        
        vector<vector<bool> > ev;
        
        for(int i = 0; i < row; i++){
            vector<bool> cv(col, false);
            ev.push_back(cv);
        }
        
        return ev;
        
    }
public:
    bool isMatch(const char *s, const char *p) {
        
        if(*s == '\0' && *p == '\0'){
            return true;
        }
        
        if(*s == '\0' || *p == '\0'){
            return false;
        }
        
        int lens = getLen(s);
        int lenp = getLen(p);
        
        vector<vector<bool> > matchTable = genEmtpyVector(lenp, lens);
        
        int start = 0;
        for(int i = 0; i < lenp; i++){
            char pi = *(p + i);
            if(i > 0){
                start = pi == '*' ? start : start + 1;
            }
            for(int j = start; j < lens; j++){
                char sj = *(s + j);
                if(pi == '*'){
                    if(j == 0 && i == 0){
                        matchTable[i][j] = true;
                    }
                    else if(j == 0){
                        matchTable[i][j] = matchTable[i - 1][j];
                    }
                    else if(i == 0){
                        matchTable[i][j] = matchTable[i][j - 1];
                    }
                    else{
                        matchTable[i][j] = matchTable[i - 1][j - 1] || matchTable[i - 1][j] || matchTable[i][j - 1];
                    }
                }
                else if(pi == '?' || pi == sj){
                    if(j - 1 < 0){
                        matchTable[i][j] = true;
                    }
                    else if(i - 1 < 0){
                        matchTable[i][j] = false;
                    }
                    else{
                        matchTable[i][j] = matchTable[i - 1][j - 1];
                    }
                }
                else{
                    matchTable[i][j] = false;
                }
            }
        }
        
        return matchTable[lenp - 1][lens - 1];
        
    }
};
