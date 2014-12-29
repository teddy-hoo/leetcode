#define MAX_INT 2147483647

class Solution {
private:
    unsigned int searchResult(long long int dividend, long long int divisor){
        unsigned int result = 0;
        while(1){
            long long int base = 1;
            long long int middleBase = divisor;
            long long int cachedBase = -1;
            long long int preBase = 0;
            while(middleBase < dividend){
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
            dividend -= middleBase >> 1;
            result += base >> 1;
        }
    }
public:
    int divide(int dividend, int divisor) {
        long long int dvd = dividend;
        long long int dvs = divisor;
        if(dividend == -2147483648 && divisor == -1){
            return MAX_INT;
        }
        if(dvs == 0){
            return MAX_INT;
        }
        if(dvd == 0){
            return 0;
        }
        bool nagtive = false;
        if(dvd < 0 ^ dvs < 0){
            nagtive = true;
        }
        if(dvd < 0){
            dvd = 0 - dvd;
        }
        if(dvs < 0){
            dvs = 0 - dvs;
        }
        unsigned int result = searchResult(dvd, dvs);
        return nagtive ? 0 - result : result;
    }
};
