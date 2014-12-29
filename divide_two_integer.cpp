#define MAX_INT 2147483647

class Solution {
private:
    int searchResult(int dividend, int divisor){
        int result = 0;
        while(1){
            int base = 1;
            int middleBase = divisor;
            int cachedBase = -1;
            int preBase = 0;
            while(middleBase < dividend && middleBase > cachedBase){
                cachedBase = middleBase;
                middleBase = middleBase << 1;
                preBase = base;
                base = base << 1;
            }
            if(middleBase == dividend){
                result += base;
                return result;
            }
            if(base == 1){
                return result;
            }
            if(middleBase <= cachedBase){
                dividend -= cachedBase;
                result += preBase;
            }
            else{
                dividend -= middleBase >> 1;
                result += base >> 1;
            }
            cout << dividend << endl;
            cout << base << endl;
            cout << result << endl;
        }
    }
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0){
            return MAX_INT;
        }
        if(dividend == 0){
            return 0;
        }
        bool nagtive = false;
        if(dividend < 0 ^ divisor < 0){
            nagtive = true;
        }
        if(dividend < 0){
            dividend = 0 - dividend;
        }
        if(divisor < 0){
            divisor = 0 - divisor;
        }
        int result = searchResult(dividend, divisor);
        return nagtive ? 0 - result : result;
    }
};