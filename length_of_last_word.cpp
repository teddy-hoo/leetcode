class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        bool hasNext = false;
        for(int i = 0; s[i] != '\0'; i ++){
            if(s[i] != ' '){
                length = hasNext ? 1 : length + 1;
                hasNext = false;
            }
            if(s[i] == ' ')
                hasNext = true;
        }
        return length;
    }
};
