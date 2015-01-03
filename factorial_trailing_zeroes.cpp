class Solution {
public:
    int trailingZeroes(int n) {
    	int sum = 0;
    	int tmp;
    	while(n > 0){
    	    tmp = n / 5;
    		sum += tmp;
    		n = tmp;
    	}
    	return sum;
    }
};
