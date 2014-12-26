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
		map<long long int, int> rem;
		map<long long int, int>::iterator iter;
		int pos = 0;
		while(remainder != 0){
			iter = rem.find(remainder);
			if(iter != rem.end()){
				str.insert(str.begin() + rem[remainder], '(');
				str += ")";
				return str;
			}
			rem[remainder] = pos++;
			remainder = remainder * 10;
			int quotient = remainder / denominator;
			str += quotient + '0';
			remainder = remainder % denominator;
		}
		return str;
	}
	string quotientToString(long long int quotient){
		string str = "";
		if(quotient == 0){
			return str + "0";
		}
		while(quotient != 0){
			long long int remainder = quotient % 10;
			str += remainder + '0';
			quotient = quotient / 10;
		}
		reverse(str);
		return str;
	}
public:
	string fractionToDecimal(int numerator, int denominator) {
		string result;
		if(denominator == 0){
			return result;
		}
		if(numerator == 0){
			return "0";
		}
		long long int quotient = numerator / denominator;
		long long int remainder = numerator % denominator;
		if(numerator < 0 ^ denominator < 0 ) {
			result += '-';
		}
		string quetientStr = quotientToString(quotient);
		result += quetientStr;
		if(remainder == 0){
			return result;
		}
		string remainderStr = remainderToString(remainder, denominator);
		quetientStr += ".";
		quetientStr += remainderStr;
		return quetientStr;
	}
};
