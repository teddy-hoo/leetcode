class Solution {
private:
	void reverse(string &str){
		int begin = 0;
		int end = str.size() - 1;
		while(begin < end){
			char tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;
			begin++;
			end--;
		}
	}
	string remainderToString(long long int remainder, int denominator){
		string str = "";
		int preValue = remainder;
		while(remainder != 0){
			remainder = remainder * 10;
			int quotient = remainder / denominator;
			str += quotient + '0';
			if(quotient == preValue){
				break;
			}
			preValue = quotient;
			remainder = remainder % denominator;
		}
		if(str.size() >= 2 && str[str.size() - 1] == str[str.size() - 2]){
			str[str.size() - 2] = '(';
			str += ')';
		}
		return str;
	}
	string quotientToString(int quotient){
		string str = "";
		if(quotient == 0){
			return str + "0";
		}
		while(quotient != 0){
			int remainder = quotient % 10;
			str += remainder + '0';
			quotient = quotient / 10;
		}
		reverse(str);
		return str;
	}
public:
	string fractionToDecimal(int numerator, int denominator) {
		if(denominator == 0){
			return NULL;
		}
		int quotient = numerator / denominator;
		long long int remainder = numerator % denominator;
		string result = "";
		if(numerator == 0){
			return "0";
		}
		if(numerator < 0 ^ denominator < 0 ) {
			result += '-';
		}
		string quetientStr = quotientToString(quotient);
		string remainderStr = remainderToString(remainder, denominator);
		if(remainderStr != ""){
			quetientStr += ".";
			quetientStr += remainderStr;
		}
		return quetientStr;
	}
};
