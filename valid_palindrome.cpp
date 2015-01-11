class Solution {
private:
    int validChar(char c){
        if(c <= 'Z' && c >= 'A'){
            return 1;
        }
        if(c <= 'z' && c >= 'a'){
            return 2;
        }
        if(c <= '9' && c >= '0'){
            return 5;
        }
        return 0;
    }
    int getValue(char c, int type){
        int value = -1;
        if(type == 1){
            value = c - 'A';   
        }
        else if(type == 2){
            value = c - 'a';
        }
        else {
            value = c - '0';
        }
        return value;
    }
public:
    bool isPalindrome(string s) {
        
        int len = s.size();
        
        int begin = 0;
        int end = len - 1;
        
        while(begin < end){
            char b = s[begin];
            int tb = validChar(b);
            while(!tb && begin < end){
                begin ++;
                b = s[begin];
                tb = validChar(b);
            }
            if(begin >= end){
                break;
            }
            char e = s[end];
            int te = validChar(e);
            while(!te && begin < end){
                end--;
                e = s[end];
                te = validChar(e);
            }
            if(begin >= end){
                break;
            }
            if(tb + te > 5 && tb != te){
                return false;
            }
            if(getValue(b, tb) != getValue(e, te)){
                return false;
            }
            begin++;
            end--;
        }
        
        return true;
        
    }
};