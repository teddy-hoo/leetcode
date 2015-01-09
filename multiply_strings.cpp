class Solution {
private:
    string multiplySingle(string num, char multiplior){
        int len = num.size();
        int value = multiplior - '0';

        string s;

        int carry = 0;
        for(int i = len - 1; i >= 0; i--){
            int val = num[i] - '0';
            int res = val * value + carry;
            carry = res / 10;
            s.insert(s.begin(), (res % 10) + '0');
        }

        if(carry > 0){
            s.insert(s.begin(), carry + '0');
        }

        return s;
    }
    string plus(string result, string multiplition, int pos){
        int lenr = result.size();
        int lenm = multiplition.size();

        string s;

        if(pos > 0){
            s = result.substr(lenr - pos, pos);
        }

        int carry = 0;
        int indexr = lenr - pos - 1;
        int indexm = lenm - 1;
        int res;
        while(indexr >= 0 && indexm >= 0){
            int valr = result[indexr] - '0';
            int valm = multiplition[indexm] - '0';
            res = valr + valm + carry;
            s.insert(s.begin(), res % 10 + '0');
            carry = res / 10;
            indexr--;
            indexm--;
        }

        while(indexr >= 0 && carry > 0){
            int valr = result[indexr] - '0';
            res = valr + carry;
            s.insert(s.begin(), res % 10 + '0');
            carry = res / 10;
            indexr--;
        }
        if(carry > 0 && indexm < 0){
            s.insert(s.begin(), carry + '0');
            carry = 0;
        }

        string as;
        while(indexm >= 0){
            int valm = multiplition[indexm] - '0';
            res = valm + carry;
            as.insert(as.begin(), res % 10 + '0');
            carry = res / 10;
            indexm--;
        }
        if(carry > 0){
            as.insert(as.begin(), carry + '0');
        }

        return as + s;
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
        
        if(num1 == "0" || num2 == "0"){
            return result;
        }

        for(int i = len1 - 1; i >= 0; i--){
            string multiplition = multiplySingle(num2, num1[i]);
            result = plus(result, multiplition, len1 - i - 1);
        }

        return result;
    }
};