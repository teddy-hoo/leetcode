/**
 * dynamic programming algorithm
 * time:   O(n)
 * space:  O(0)
 * date:   25-01-2015
 * author: Teddy
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] != ' '){
                length++;
            }
            else{
                // consider there maybe multiple spaces together
                while(s[i] == ' '){
                    i++;
                }
                // if reaching the end of the string, return the length
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
