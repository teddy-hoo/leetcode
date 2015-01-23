class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] != ' '){
                length++;
            }
            else{
                while(s[i] == ' '){
                    i++;
                }
                if(s[i] == '\0'){
                    return length;
                }
                i--;
                length = 0;
            }
        }
        return length;
    }
};
