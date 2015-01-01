class Solution {
public:
    int atoi(const char *str) {
        long long int result = 0;
        bool isNegative = false;
        int index = 0;
        while(str[index] != '\0' && str[index] == ' '){
            index++;
        }
        if(str[index] == '\0'){
            return result = 0;
        }
        if(str[index] == '-'){
            isNegative = true;
            index++;
        }
        else if(str[index] == '+'){
            isNegative = false;
            index++;
        }
        for(; str[index] != '\0' && str[index] <= '9' && str[index] >= '0'; index++){
            result = result * 10 + (str[index] - '0');
            if(result > INT_MAX){
                break;
            }
        }
        if(result > INT_MAX){
            if(isNegative){
                result = 0 - result;
                if(result < INT_MIN){
                    result = INT_MIN;
                }
            }
            else{
                result = INT_MAX;
            }
        }
        else{
            result = isNegative ? 0 - result : result;
        }
        return result;
    }
};
