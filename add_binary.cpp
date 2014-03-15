class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int indexa = a.length() - 1;
        int indexb = b.length() - 1;
        string rawresult;
        while(indexa > -1 && indexb > -1){
            if(carry == 1){
                if(a[indexa] == '1' && b[indexb] == '1'){
                    rawresult += '1';
                    carry = 1;
                }
                else if((a[indexa] == '0' && b[indexb] == '1') || (a[indexa] == '1' && b[indexb] == '0')){
                    rawresult += '0';
                    carry = 1;
                }
                else if(a[indexa] == '0' && b[indexb] == '0'){
                    rawresult += '1';
                    carry = 0;
                }
            }
            else if(carry == 0){
                if(a[indexa] == '1' && b[indexb] == '1'){
                    rawresult += '0';
                    carry = 1;
                }
                else if((a[indexa] == '0' && b[indexb] == '1') || (a[indexa] == '1' && b[indexb] == '0')){
                    rawresult += '1';
                    carry = 0;
                }
                else if(a[indexa] == '0' && b[indexb] == '0'){
                    rawresult += '0';
                    carry = 0;
                }
            }
            indexa--;
            indexb--;
        }
        while(indexa > -1){
            if(carry == 0){
                if(a[indexa] == '1'){
                    carry = 0;
                    rawresult += '1';
                }
                else{
                    carry = 0;
                    rawresult += '0';
                }
            }
            else{
                if(a[indexa] == '1'){
                    carry = 1;
                    rawresult += '0';
                }
                else{
                    carry = 0;
                    rawresult += '1';
                }
            }
            indexa--;
        }
        while(indexb > -1){
            if(carry == 0){
                if(b[indexb] == '1'){
                    carry = 0;
                    rawresult += '1';
                }
                else{
                    carry = 0;
                    rawresult += '0';
                }
            }
            else{
                if(b[indexb] == '1'){
                    carry = 1;
                    rawresult += '0';
                }
                else{
                    carry = 0;
                    rawresult += '1';
                }
            }
            indexb--;
        }
        if(carry == 1)
            rawresult += '1';
        string result;
        for(int i = rawresult.size() - 1; i > -1; i--)
            result += rawresult[i];
        return result;
    }
};
