#define MAX_INT 2147483647

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0){
            return MAX_INT;
        }
        if(dividend == 0){
            return 0;
        }
        int small = 0;
        int large = dividend;
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
        int quotient = 1;
        while(small < large){
            cout << small << " " << large << endl;
            int middle = (small + large) >> 1;
            cout << middle << endl;
            int iter = 0;
            for(int i = 0; i < middle; i++){
                iter += divisor;
            }
            cout << iter << endl;
            if(iter == dividend){
                return middle;
            }
            else if(iter < dividend){
                small = middle + 1;
            }
            else{
                large = middle - 1;
            }
        }
        return large;
    }
};