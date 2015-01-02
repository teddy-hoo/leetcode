class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int number = 0;
        if(len <= 0){
            return number;
        }
        for(int i = 0; i < len; i++){
            number = number * 26 + s[i] - 'A' + 1;
        }
        return number;
    }
};