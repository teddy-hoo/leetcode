class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0){
    		return false;
    	}

        int scale = 1;
        int leftDigit;
        int rightDigit;

        while(x / scale >= 10){
        	scale *= 10;
        }

        while(1){
        	if(x == 0 || scale == 1){
        		return true;
        	}

        	leftDigit = x / scale;
        	rightDigit = x % 10;
        	x = x % scale;
        	scale /= 100;
        	x /= 10;
        	if(leftDigit != rightDigit){
        		return false;
        	}
        }
    }
};