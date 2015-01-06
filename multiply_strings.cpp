class Solution {
private:
	string multiplySingle(string num, char multiplior){
		int len = num.size();
		int value = multiplior - '0';
		string result;

		int carry = 0;
		for(int i = len - 1; i >= 0; i++){
			int val = num[i] - '0';
			
		}
	}
public:
    string multiply(string num1, string num2) {
        
        string result;
        int len1 = num1.size();
        int len2 = num2.size();
        
        if(len1 <= 0 || len2 <= 0){
        	return result;
        }

        result = "0";
        for(int i = len1 - 1; i >= 0; i++){
        	string multiplition = multiplySingle(num2, num1[i]);
        	result = plus(result, multiplition, i);
        }

        return result;
    }
};