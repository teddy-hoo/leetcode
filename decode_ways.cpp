class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len <= 0){
            return 0;
        }
        int cache[100000];
        cache[0] = 1;
        if(s[0] > '0' && s[0] <= '9'){
            cache[1] = 1;
        }
        else{
            cache[1] = 0;
        }
        for(int i = 1; i < len; i++){
            if(s[i - 1] == '1' || 
              (s[i - 1] == '2' && s[i] <= '6')){
                if(s[i] == '0'){
                    cache[i + 1] = cache[i - 1];
                }
                else{
                    cache[i + 1] = cache[i] + cache[i - 1];
                }
            }
            else if(s[i] > '0'){
                cache[i + 1] = cache[i];
            }
            else{
                return 0;
            }
        }
        return cache[len];
    }
};
