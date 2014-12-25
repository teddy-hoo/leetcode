// method
// 1. calculate quotient and remainder
// 2. convent quetient and remainder to string seperaterly
// have a try tomorrow

class Solution {
private:
	float calDecimal(int numerator, int denominator){
		float result = 0;
		float base = 1;
		int preQuotient = numerator;
		while(numerator != 0){
			base /= 10;
			int quotient = numerator * 10 / denominator;
			int remainder = numerator * 10 % denominator;
			result += quotient * base;
			numerator = remainder;
			if(preQuotient == quotient){
				break;
			}
			preQuotient = quotient;
		}
		return result;
	}
	void reverse(string &str){
		int begin = 0;
		int end = str.size() - 1;
		while(begin < end){
			char tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;
		}
	}
	string decimalToString(float decimal){
		string result = "";
		int intPart = decimal;
		float decPart = decimal - ((int)decimal);
		do{
			int remainder = intPart % 10;
			result += remainder + '0';
			intPart /= 10;
		}while(intPart != 0);
		reverse(result);
		if(decPart != 0){
			result += '.';
		}
		while(decPart != 0){
			int tmp = decPart * 10;
			result += tmp + '0';
			decPart = decimal * 10 - ((int)(decimal * 10));
		}
		if(result.size() >= 2 && result[result.size() - 1] == result[result.size() - 2]){
			result[result.size() - 2] = '(';
			result += ')';
		}
		return result;
	}
public:
	string fractionToDecimal(int numerator, int denominator) {
		if(denominator == 0){
			return NULL;
		}
		float decimal = calDecimal(numerator, denominator);
		return decimalToString(decimal);
	}
};